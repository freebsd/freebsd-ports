--- /usr/ports/devel/cocktail/work/cocktail-9309//./rex/m2c/Nfa.c	Tue Feb 15 14:27:58 1994
+++ ./rex/m2c/Nfa.c	Thu Aug  5 18:49:06 2004
@@ -227,7 +227,8 @@
   Nfa_TransitionRange t2;
 
   t2 = Nfa_NoTransition;
-  while (t1 != Nfa_NoTransition) {
+  while ((t1 != Nfa_NoTransition) 
+	 &&(t1 != (Nfa_TransitionRange)DEAD_ALLOCATE)){
     {
       register C_1_Transition *W_3 = &TransitionTablePtr->A[t1];
 
