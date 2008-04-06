--- mapm/state.c.orig	2008-04-04 20:05:29.000000000 +0000
+++ mapm/state.c	2008-04-03 19:37:40.000000000 +0000
@@ -734,7 +734,7 @@
 {
     int i, usenum;
 
-    fprint(fp,"*MapmakerStatusInfo:\n");
+    fprint(fp,WRS("*MapmakerStatusInfo:\n"));
 
     sf(ps,"*PrintNames: %d\n",print_names); fpr(fp);
     sf(ps,"*Tolerance: %lf\n",tolerance); fpr(fp);
@@ -852,5 +852,5 @@
 	load_table(context[i]->sequence_history,fp,INDEX_BY_NUMBER,num);
     }
 
-    if (the_seq_history_num>0) set_current_seq("none",FALSE);
+    if (the_seq_history_num>0) set_current_seq(WRS("none"),FALSE);
 }
