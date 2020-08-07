#include<iostream>
#include<cmath>
using namespace std;

  struct node{
 int num;
 struct node *next;
 };

void create (struct node *head, int n)
{
    struct node *p;
    struct node *temp=new node();
    temp->num=n;
    p=head;
    while(p->next)
        p=p->next;
    p->next=temp;
    temp->next=NULL;
}
 void displayList(struct node *head)
{
    struct node *tmp;
    if(head == NULL)
    {
       cout<<" List is empty.";
    }
    else
    {
        tmp = head;
        while(tmp != NULL)
        {
            cout<<"   "<< tmp->num;
                        tmp = tmp->next;
        }
    }
}
void intersection(struct node * head1, struct node* head2)
{
    struct node *p1,*p2;
    int c1=0,c2=0,d;
    p1=head1;
    p2=head2;
    while(p1)
    {
        p1=p1->next;
        c1++;
    }
    while(p2)
    {
        p2=p2->next;
        c2++;
    }
    d=abs(c1-c2);
    cout<<endl;

    p1=head1;
    while(d--)
    {
        p1=p1->next;
    }
    p2=head2;
    while(p1!=p2)
    {
        p1=p1->next;
        p2=p2->next;
    }
    cout<<endl<<(*p1).num;
}

 int main()
 {
    struct node *head1=NULL,*head2=NULL;
    head1=new node();
    head2=new node();
    head1->num=1;
    create (head1,2);
    create (head1,3);
    create (head1,4);
    create (head1,5);
    create (head1,6);
    create (head1,7);
    create (head1,8);
    head2->num=9;
    create(head2,10);
    head2->next->next=head1->next->next->next->next->next;
    displayList(head1);
    cout<<endl;
    displayList(head2);
    intersection(head1,head2);

}
