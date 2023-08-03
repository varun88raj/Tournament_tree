#include<iostream>
#include<iomanip>
#include<cmath>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct Team
{
        char TeamName[20];
        int points;
        int wickets;
        struct Team *lchild;
        struct Team *rchild;
};
class Queue
{
        private:
                Team*Q[128];
                int rear;
                int Front;
        public:
                void rearFront_intialize()
                {
                        rear=-1;
                        Front=-1;
                }
                void enqueue(Team*Q1)
                {
                        if(rear==128)
                        {
                                cout<<"Overflow \n";
                        }
                        else
                        {
                                rear=rear+1;
                                Q[rear]=Q1;
                        }
                }
                Team*dequeue()
                {
                        if(rear==Front)
                        {
                                cout<<"Underflow \n";
                                return 0;
                        }
                        else
                        {
                                Front++;
                                return Q[Front];
                        }
                }
                int isEmpty()
                {
                        if(Front==rear)
                        {
                                return 1;
                        }
                        else
                        {
                                return 0;
                        }
                }
};
Team*root;
void create(char *TN)
{
        Team*N=new Team;
        N->points=0;
        strcpy(N->TeamName,TN);
        N->lchild=NULL;
        N->rchild=NULL;
        root=N;
}
void Insert(char *TN)
{
        Queue q;
        q.rearFront_intialize();
        q.enqueue(root);
        while(q.isEmpty()==0)
        {
                struct Team*temp=q.dequeue();
                if(temp->lchild==NULL)
                {
                        struct Team*N=new Team;
                        strcpy(N->TeamName,TN);
                        N->points=0;
                        N->lchild=NULL;
                        N->rchild=NULL;
                        temp->lchild=N;
                        break;
                }
                else
                {
                        q.enqueue(temp->lchild);
                }
                if(temp->rchild==NULL)
                {
                        struct Team*N=new Team;
                        strcpy(N->TeamName,TN);
                        N->points=0;
                        N->lchild=NULL;
                        N->rchild=NULL;
                        temp->rchild=N;
                        break;
                }
                else
                {
                        q.enqueue(temp->rchild);
                }
        }
}
void preorder(Team*n)
{
        if(n!=NULL)
        {
                cout<<n->TeamName<<" ";
                cout<<n->points<<endl;
                preorder(n->lchild);
                preorder(n->rchild);
        }
}
void postorder(Team*n)
{
        if(n!=NULL)
        {
                postorder(n->lchild);
                postorder(n->rchild);
                cout<<n->TeamName<<" "<<n->points<<endl;
        }
}
void inorder(Team*n)
{
        if(n!=NULL)
        {
                inorder(n->lchild);
                cout<<n->TeamName<<" "<<n->points<<endl;
                inorder(n->rchild);
        }
}
void travelorder(Team*n)
{
        //char name[20];
        if(strcmp( (n->lchild)->TeamName,"na") == 0)
        {
                travelorder(n->lchild);
                travelorder(n->rchild);
        }
        else
        {
                int random;
                random=rand()%2;
                char match[2][20];
                strcpy(match[0],n->lchild->TeamName);
                strcpy(match[1],n->rchild->TeamName);
                cout<<"\n"<<(n->lchild)->TeamName<<" vs "<<(n->rchild)->TeamName<<"\n\n";
                cout<<"Enter First innings score and wickets of "<<match[random]<<" ";
                if(random==0)
                {
                        int error1=0,error2=0;
                        do
                        {
                                if(error1>0)
                                {
                                        cout<<"Score can't be negative ";
                                }
                                cin>>n->lchild->points;
                                error1++;
                        }while(n->lchild->points<0);
                        cout<<"Wickets ";
                        do
                        {
                                if(error2>0)
                                {
                                        cout<<"Wickets can't be negative or exceed a limit ";
                                }
                                cin>>n->lchild->wickets;
                                error2++;
                        }while(n->lchild->wickets<0||n->lchild->wickets>10);
                        error1=0,error2=0;
                        cout<<"Enter Second innings score and wickets of "<<match[1]<<" ";
                        do
                        {
                                if(error1>0)
                                {
                                        cout<<"Score can't be negative or second innings score can't exceed by 7  ";
                                }
                                cin>>n->rchild->points;
                                error1++;
                        }while(n->rchild->points<0||(n->rchild->points-n->lchild->points)>7);
                        cout<<"Wickets ";
                        do
                        {
                                if(error2>0)
                                {
                                        cout<<"Wickets can't be negative or exceed a limit ";
                                }
                                cin>>n->rchild->wickets;
                                error2++;
                        }while(n->rchild->wickets<0||n->rchild->wickets>10);
                }
                else if(random==1)
                {
                        int error1=0,error2=0;;
                        do
                        {
                                if(error1>0)
                                {
                                        cout<<"Score can't be negative ";
                                }
                                cin>>n->rchild->points;
                                error1++;
                        }while(n->rchild->points<0);
                        cout<<"Wickets ";
                        do
                        {
                                if(error2>0)
                                {
                                        cout<<"Wickets can't be negative or exceed a limit ";
                                }
                                cin>>n->rchild->wickets;
                                error2++;
                        }while((n->rchild->wickets<0)||(n->rchild->wickets>10));
                        error1=0,error2=0;
                        cout<<"Enter Second innings score and wickets of "<<match[0]<<" ";
                        do
                        {
                                if(error1>0)
                                {
                                        cout<<"Score can't be negative or second innings score can't exceed by 7  ";
                                }
                                cin>>n->lchild->points;
                                error1++;
                        }while(n->lchild->points<0||(n->lchild->points-n->rchild->points)>7);
                        cout<<"Wickets ";
                        do
                        {
                                if(error2>0)
                                {
                                        cout<<"Wickets can't be negative or exceed a limit ";
                                }
                                cin>>n->lchild->wickets;
                                error2++;
                        }while(n->lchild->wickets<0||n->lchild->wickets>10);
                }
                if(n->lchild->points>n->rchild->points)
                {
                        strcpy(n->TeamName,n->lchild->TeamName);
                        if(random==0)
                        {
                              cout<<"\n"<<n->lchild->TeamName<<" won by "<<n->lchild->points-n->rchild->points<<" run(s)\n";
                        }
                        else if(random==1)
                        {
                                cout<<"\n"<<n->lchild->TeamName<<" won by "<<10-n->lchild->wickets<<" wicket(s)\n";
                        }
                }
                else if(n->lchild->points<n->rchild->points)
                {
                        strcpy(n->TeamName,n->rchild->TeamName);
                        if(random==0)
                        {
                              cout<<"\n"<<n->rchild->TeamName<<" won by "<<10-n->rchild->wickets<<" wicket(s)\n";
                        }
                        else if(random==1)
                        {
                                cout<<"\n"<<n->rchild->TeamName<<" won by "<<n->rchild->points-n->lchild->points<<" run(s)\n";
                        }
                }
                else
                {
                        int s1,s2;
                        cout<<"Match tied \n";
                        do
                        {
                                do
                                {
                                        cout<<"Enter super over score of "<<match[0]<<" ";
                                        cin>>s1;
                                }while(s1<0);
                                do
                                {
                                        cout<<"Enter super over score of "<<match[1]<<" ";
                                        cin>>s2;
                                }while(s2<0);
                        }while(s1==s2);
                        if(s1>s2)
                        {
                                strcpy(n->TeamName,n->lchild->TeamName);
                                cout<<n->TeamName<<" won in super over\n";
                        }
                        else
                        {
                                strcpy(n->TeamName,n->rchild->TeamName);
                                cout<<n->TeamName<<" won in super over\n";
                        }
                }
                cout<<"\n"<<n->TeamName<<" advances to next level \n";
        }
}
void print(int n,int max,char*t)
{
        int temp,i;
        if(max!=0)
        {
                int binaryNum[max];
                for(i=0;i<max;i++)
                {
                        binaryNum[i]=0;
                }
                i=0;
                while(n>0)
                {
                        binaryNum[i]=n % 2;
                        n = n / 2;
                        i++;
                }
                int k=0;
                for(int j=max-1;j>=max/2;j--)//revering to get proper binary form
                {
                        temp=binaryNum[j];
                        binaryNum[j]=binaryNum[k];
                        binaryNum[k]=temp;
                        k++;
                }
                struct Team*ptr=root;
                for(int x=0;x<max;x++)
                {
                        if(binaryNum[x]==0)
                        {
                                ptr=ptr->lchild;
                        }
                        else if(binaryNum[x]==1)
                        {
                                ptr=ptr->rchild;
                        }
                }
                strcpy(t,ptr->TeamName);
        }
        else
        {
              strcpy(t,root->TeamName);
        }
}
void pattern(int n,char teamname[][20],int max)
{
        int p=2,j=n;
        int v=0;
        for(int i=0;i<=log2(n);i++)
        {
                //int M;
                for(int k=1;k<=p;k++)
                {
                        if(k==1)
                        {
                                for(int l=1;l<j;l++)
                                {
                                        for(int p=0;p<(max+2);p++)
                                        {
                                                cout<<" ";
                                        }
                                }
                        }
                        else if(k%2==0)
                        {
                                cout<<"|";
                                int diff;
                                diff=(max-strlen(teamname[v]));
                                for(int d=1;d<=diff/2;d++)
                                {
                                        cout<<" ";
                                }
                                cout<<teamname[v];
                                if(diff%2==0)
                                {
                                        for(int d=1;d<=diff/2;d++)
                                        {
                                                cout<<" ";
                                        }
                                }
                                else
                                {
                                        for(int d=1;d<=(diff/2)+1;d++)
                                        {
                                                cout<<" ";
                                        }
                                }
                                v++;
                                cout<<"|";
                        }
                        else if(k%2==1)
                        {
                                for(int m=1;m<j*2;m++)
                                {
                                        for(int p=0;p<(max+2);p++)
                                        {
                                                cout<<" ";
                                        }
                                }
                        }
                }
                p=p*2;
                j=j/2;
                cout<<"\n\n\n";
        }

}
void Traverse(Team *n,int n1)
{
        int i;
        for(i=1;i<log2(n1) +1;i++)
        {
                travelorder(n);
        }
        cout<<"\n"<<n->TeamName<<" IS THE WINNER OF THE TOURNAMENT "<<endl;
}
int main()
{
        int i,n,j,nodes=0,index=0;
        char str[20];
        cout<<"\n TOURNAMENT \n";
        do
        {
                cout<<"\n Enter the Number of Teams : ";
                cin>>n;
        }while(log2(n) != int(log2(n)));
        for(i=1;i<(n);i=i*2)
        {
                if(i==1)
                {
                create("na");
                }
                else
                {
                        for(j=1;j<=i;j++)
                        {
                                Insert("na");
                        }
                }
        }
        for(int i=n;i>=1;i=i/2)
        {
                nodes+=i;
        }
        char TeamPrint[nodes][20];
        for(i=1;i<=n;i++)
        {
                cout<<"\n Enter Team Name : ";
                cin>>str;
                Insert(str);
        }
        Traverse(root,n);
        for(int a=1;a<=n;a=a*2)
        {
                for(int b=0;b<a;b++)
                {
                        print(b,log2(a),TeamPrint[index]);
                        index++;
                }
        }
        cout<<"\n\n";
        int max;
        max=strlen(TeamPrint[0]);
        for(int p=0;p<nodes;p++)
        {
                if(max<strlen(TeamPrint[p]))
                {
                        max=strlen(TeamPrint[p]);
                }
        }
        pattern(n,TeamPrint,max);
}
