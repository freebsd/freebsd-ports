--- exp_ch4.adb.orig	Fri Sep  1 10:13:50 2000
+++ exp_ch4.adb	Fri Feb  8 21:20:29 2002
@@ -2623,7 +2623,7 @@
             Expand_Concatenate_Other (Cnode, Opnds);
          end if;
 
-         exit when Cnode = N;
+         exit Outer when Cnode = N;
          Cnode := Parent (Cnode);
       end loop Outer;
    end Expand_N_Op_Concat;
