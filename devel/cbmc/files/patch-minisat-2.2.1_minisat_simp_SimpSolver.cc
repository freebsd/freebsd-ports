--- minisat-2.2.1/minisat/simp/SimpSolver.cc.orig	2011-02-21 13:31:17 UTC
+++ minisat-2.2.1/minisat/simp/SimpSolver.cc
@@ -130,8 +130,6 @@ lbool SimpSolver::solve_(bool do_simp, bool turn_off_s
     return result;
 }
 
-
-
 bool SimpSolver::addClause_(vec<Lit>& ps)
 {
 #ifndef NDEBUG
@@ -227,10 +225,12 @@ bool SimpSolver::merge(const Clause& _ps, const Clause
         if (var(qs[i]) != v){
             for (int j = 0; j < ps.size(); j++)
                 if (var(ps[j]) == var(qs[i]))
+                {
                     if (ps[j] == ~qs[i])
                         return false;
                     else
                         goto next;
+                }
             out_clause.push(qs[i]);
         }
         next:;
@@ -261,10 +261,12 @@ bool SimpSolver::merge(const Clause& _ps, const Clause
         if (var(__qs[i]) != v){
             for (int j = 0; j < ps.size(); j++)
                 if (var(__ps[j]) == var(__qs[i]))
+                {
                     if (__ps[j] == ~__qs[i])
                         return false;
                     else
                         goto next;
+                }
             size++;
         }
         next:;
