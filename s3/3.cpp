#include<iostream>
using namespace std;
class node
{
   node*left,*right;
   int data;
   public:
   node()
   {
      left=right=NULL;
      data=0;
   }
   friend class btree;
};
class btree
{   node*root;
   public:
   btree()
   {
      root=NULL;
   }
 void display()
   {    if(root==NULL)
      {         cout<<"\nroot is empty...";
         return;}
      else
      {inorder_rec(root);     
         }   }
void insert()
   {      node*travel,*temp;
    temp=new node();
    cout<<"\nEnter the data for the new node   :";
    cin>>temp->data;//4
    if(root==NULL)
      {         root=temp;
      }
      else
      {
         travel=root;//2
         int ins=0;//flag
        while(ins!=1)
        {
               if(temp->data<travel->data)//4 <2//   4<5
               {
                  if(travel->left!=NULL)//5->left ull
                  {
                     travel=travel->left;
                  }
                  else
                  {
                     travel->left=temp;
                     ins=1;
                  }
               }
               if(temp->data>=travel->data)//4>=2//4>=3//   4>=5
               {
                  if(travel->right!=NULL)//3!null//
                  {
                     travel=travel->right;//travel ==3travel==5.....
                  }
                  else
                  {
                     travel->right=temp;
                     ins=1;
                  }
               }
         }
      }
   }
   void create()
   {
      if(root!=NULL)
      {
         cout<<"\nTree already created....";
         return;
      }
      else
      {
         int n;
         cout<<"\nhow many nodes do you wan tin your treee : ";
         cin>>n;
         for(int i=0;i<n;i++)
         {
            insert();
         }
      }
   }
void inorder_rec(node*travel)
   {
      if(travel!=NULL)
      {
         inorder_rec(travel->left);
         cout<<travel->data<<"  ";
         inorder_rec(travel->right);
      }   }
   void search()
   {
      int key;//
      node*temp;
     
      int count=1;
      if(root==NULL)
      {
         cout<<"\nroot is empty...";
         return;
      }

      else
      {
      temp=root;
      cout<<"\nEnter the key to searched : ";
      cin>>key;//
      while(temp!=NULL)
      {
          if(temp->data==key)
         {
            cout<<"\nKey is presnt in the btree...";
            cout<<"\nNumber of comparisions are "<<count;
            break;
         }
       else  if(temp->data>key)
         {
            temp=temp->left;
            count++;
         }
         else if (temp->data <= key)
         {
               temp=temp->right;
               count++;
         }}      }
    if(temp==NULL)
      {
         cout<<"\nkey is not present in the binary tree....";
         return;}}
   void mirror()
   {
      if(root==NULL)
      {
         cout<<"\nroot is empty";
         return;
      }
      else
      {
         miroring(root);
      }   }
   node* miroring(node*travel)
   {
     miroring(travel->left);//
     miroring(travel->right);//
     node*temp=travel->left;//
     travel->left=travel->right;
     travel->right=temp;
     return travel;//
   }
   int count(node*travel)
   {
      if (travel==NULL)
      return 0;
      if (travel->left==NULL&&travel->right==NULL)
      return 1;
      return max(count(travel->left),count(travel->right))+1;
   }
   void maxnornode()
   {
      int maxii=count(root);
      cout<<"\nthe max nor of nodes in the longesh pah is : ";
      cout<<maxii;
   }
   void minmax()
   {
      node*travel=root;
      while(travel->left!=NULL)
      {
            travel=travel->left;
      }
      cout<<"\nsmallest number is : "<<travel->data;
      travel=root;
      while(travel->right!=NULL)
      {
            travel=travel->right;
      }
      cout<<"\nLargest number is : "<<travel->data; 
   }

};

int main()
{
   int ch;
   btree b;
   do
   {
      cout<<"\n\n~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~\n1.create\n2.insert\n3.search\n4.delete\n5.mirror\n6.maxmin\n7.highst no of node\n8.display\n9.exit\n\nEnter your choice:";
      cin>>ch;
      switch (ch)
      {
      case 1:b.create();break;
      case 2:b.insert();break;
      case 3:b.search();break;
      case 5:b.mirror();break;
      case 6:b.minmax();break;
      case 7:b.maxnornode();break;
      case 8:b.display();break;
      case 9:cout<<"\nExiting";break;
      default:
         cout<<"\nEnter valid choice";
      }
   }while(ch!=9);
   return 0;
}