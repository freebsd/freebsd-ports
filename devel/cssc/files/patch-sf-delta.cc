--- sf-delta.cc.orig	Fri Oct  1 18:10:43 2004
+++ sf-delta.cc	Fri Oct  1 18:31:01 2004
@@ -533,8 +533,10 @@
       return false;
     }
   FileDeleter another_cleaner(dname, false);
+
+  delta d;
   
-  struct subst_parms parms(get_out, NULL, delta(), 
+  struct subst_parms parms(get_out, NULL, d,
                            0, sccs_date()); // XXX: was sccs_date(NULL) (bad!)
   seq_state gsstate(sstate);
 
