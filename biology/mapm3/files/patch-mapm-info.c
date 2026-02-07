--- mapm/info.c.orig	1993-02-09 16:35:03 UTC
+++ mapm/info.c
@@ -966,9 +966,9 @@ FILE *fp;
 	   class[locus]);
 	fpr(fp);
     }
-    fprint(fp,"*Classes:\n");
+    fprint(fp,WRS("*Classes:\n"));
     for (i=0; i<NUM_CLASSES; i++) 
-      { fprint(fp,"*"); fprint(fp,class_name[i]); fnl(fp); }
+      { fprint(fp,WRS("*")); fprint(fp,class_name[i]); fnl(fp); }
 }
 
 
@@ -980,12 +980,12 @@ FILE *fp;
     real rate;
     char temp_locus_name[NAME_LEN+2], word[TOKLEN+1];
 
-    fgetln(fp);
+    fgetln_(fp);
     if (sscanf(ln,"%s %d %d",word,&num_groups,&num_orders)!=3 || 
 	!streq(word,"*OrderInfo:")) baddata("expected '*OrderInfo: # #'");
 
     for (locus=0; locus < raw.num_markers; locus++) {
-	fgetln(fp);
+	fgetln_(fp);
 
 	if (!nstoken(&ln,sREQUIRED,temp_locus_name,NAME_LEN+1) || 
 	    temp_locus_name[0]!='*' || len(temp_locus_name)<2)
@@ -1007,9 +1007,9 @@ FILE *fp;
 	order_next[locus]= ord_next;
 	class[locus]= class_num;
     }
-    fgetln(fp); if (!streq(ln,"*Classes:")) baddata("bad classes");
+    fgetln_(fp); if (!streq(ln,"*Classes:")) baddata("bad classes");
     for (i=0; i<NUM_CLASSES; i++) 
-      { fgetln(fp); strcpy(class_name[i],ln+1); }
+      { fgetln_(fp); strcpy(class_name[i],ln+1); }
 }
 
 
