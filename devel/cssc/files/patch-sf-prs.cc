--- sf-prs.cc.orig	Fri Oct  1 18:32:28 2004
+++ sf-prs.cc	Fri Oct  1 18:32:50 2004
@@ -43,8 +43,10 @@
 {
   sid_list no_includes, no_excludes;
   sccs_date no_cutoff;
+
+  delta d;
   
-  struct subst_parms parms(out, NULL, delta(), 0,
+  struct subst_parms parms(out, NULL, d, 0,
                            sccs_date());  // XXX: was sccs_date(NULL) (bad!)
   class seq_state state(highest_delta_seqno());
   
