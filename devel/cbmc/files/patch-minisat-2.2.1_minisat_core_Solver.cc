--- minisat-2.2.1/minisat/core/Solver.cc.orig	2011-02-21 13:31:17 UTC
+++ minisat-2.2.1/minisat/core/Solver.cc
@@ -210,7 +210,7 @@ void Solver::cancelUntil(int level) {
         for (int c = trail.size()-1; c >= trail_lim[level]; c--){
             Var      x  = var(trail[c]);
             assigns [x] = l_Undef;
-            if (phase_saving > 1 || (phase_saving == 1) && c > trail_lim.last())
+            if (phase_saving > 1 || ((phase_saving == 1) && c > trail_lim.last()))
                 polarity[x] = sign(trail[c]);
             insertVarOrder(x); }
         qhead = trail_lim[level];
@@ -666,7 +666,7 @@ lbool Solver::search(int nof_conflicts)
 
         }else{
             // NO CONFLICT
-            if (nof_conflicts >= 0 && conflictC >= nof_conflicts || !withinBudget()){
+            if ((nof_conflicts >= 0 && conflictC >= nof_conflicts) || !withinBudget()){
                 // Reached bound on number of conflicts:
                 progress_estimate = progressEstimate();
                 cancelUntil(0);
