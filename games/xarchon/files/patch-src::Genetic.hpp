--- src/Genetic.hpp.orig	Fri Oct  1 10:06:20 2004
+++ src/Genetic.hpp	Fri Oct  1 10:08:12 2004
@@ -216,9 +216,9 @@
   virtual Genetic_Operator<T> *Choose_Operator(void)
   {
     int max=(int)total_op_weight;
-    list<Genetic_Operator<T> *>::iterator start=operators.begin();
-    list<Genetic_Operator<T> *>::iterator end=operators.end();
-    list<Genetic_Operator<T> *>::iterator iter;
+    typename list<Genetic_Operator<T> *>::iterator start=operators.begin();
+    typename list<Genetic_Operator<T> *>::iterator end=operators.end();
+    typename list<Genetic_Operator<T> *>::iterator iter;
     int r=rand()%max;
     int count=0;
     for (iter=start;iter!=end;iter++) {
@@ -249,7 +249,7 @@
     Genetic_Population<T> *newpop=new Genetic_Population<T>(p->size);
     int cur_size=0;
     while (cur_size<newpop->size) {
-      Genetic_Operator<T> *op=Choose_Operator();
+      Genetic_Operator<T> *op=this->Choose_Operator();
       if ( (cur_size+op->NumOfResults())>newpop->size)
 	continue;
       for (i=0;i<op->NumOfOperands();i++) {
@@ -264,7 +264,7 @@
 	cur_size++;
       }
     }
-    newpop->Eval_Fitness(fit_func);
+    newpop->Eval_Fitness(this->fit_func);
     return newpop;
   }
 
