--- src/Problem.hpp.orig	Fri Oct  1 10:00:09 2004
+++ src/Problem.hpp	Fri Oct  1 10:05:48 2004
@@ -306,14 +306,14 @@
   virtual G Goal_Value(T *a)
   {
     if (depth==0) 
-      return tester->Goal_Value(a);
+      return this->tester->Goal_Value(a);
     
-    Goal_Test<G,T> *endtester=tester;
-    tester=new Minimax_Goal_Test(depth-1,generator,other_acc,goal_acc,tester);
+    Goal_Test<G,T> *endtester=this->tester;
+    this->tester=new Minimax_Goal_Test(depth-1,this->generator,other_acc,this->goal_acc,this->tester);
     G ret_val=Successor_Goal_Test<G,T>::Goal_Value(a);
-    delete tester;
-    tester=endtester;
-    delete next;
+    delete this->tester;
+    this->tester=endtester;
+    delete this->next;
 
     return ret_val;
   }
@@ -340,19 +340,19 @@
   
   virtual G Goal_Value(T *a)
   {
-    Goal_Accumulator <G,T> *old=goal_acc;
+    Goal_Accumulator <G,T> *old=this->goal_acc;
     Multi_Goal_Accumulator <G,T,greater<G> > *mga=new Multi_Goal_Accumulator<G,T,greater<G> >(branch);
-    goal_acc=mga;
+    this->goal_acc=mga;
     Successor_Goal_Test<G,T>::Goal_Value(a);
-    goal_acc=old;
+    this->goal_acc=old;
     for (mga->Init();!mga->IsEnd();mga->Next()) { 
       T *state=mga->Get_State();
-      Multi_Minimax_Goal_Test *next=new Multi_Minimax_Goal_Test(d-1,b,gen,other,goal_acc,tester);
+      Multi_Minimax_Goal_Test *next=new Multi_Minimax_Goal_Test(this->d-1,this->b,this->gen,other,this->goal_acc,this->tester);
       next->Goal_Value(state);
-      goal_acc->Put(accumulator->value,acc->state,acc->op);
+      this->goal_acc->Put(this->accumulator->value,this->acc->state,this->acc->op);
     }
-    goal_acc->Put(mga->Get_State(),mga->Get_Operator(),mga->Get_Result());
-    return goal_acc->Get_Value();
+    this->goal_acc->Put(mga->Get_State(),mga->Get_Operator(),mga->Get_Result());
+    return this->goal_acc->Get_Value();
   }
 };
 
