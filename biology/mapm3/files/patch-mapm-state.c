--- mapm/state.c.orig	1993-02-09 16:35:05 UTC
+++ mapm/state.c
@@ -734,7 +734,7 @@ FILE *fp;
 {
     int i, usenum;
 
-    fprint(fp,"*MapmakerStatusInfo:\n");
+    fprint(fp,WRS("*MapmakerStatusInfo:\n"));
 
     sf(ps,"*PrintNames: %d\n",print_names); fpr(fp);
     sf(ps,"*Tolerance: %lf\n",tolerance); fpr(fp);
@@ -852,5 +852,5 @@ FILE *fp;
 	load_table(context[i]->sequence_history,fp,INDEX_BY_NUMBER,num);
     }
 
-    if (the_seq_history_num>0) set_current_seq("none",FALSE);
+    if (the_seq_history_num>0) set_current_seq(WRS("none"),FALSE);
 }
