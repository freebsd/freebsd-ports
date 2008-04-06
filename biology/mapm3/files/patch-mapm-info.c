--- mapm/info.c.orig	2008-04-04 20:05:29.000000000 +0000
+++ mapm/info.c	2008-03-27 21:26:18.000000000 +0000
@@ -966,9 +966,9 @@
 	   class[locus]);
 	fpr(fp);
     }
-    fprint(fp,"*Classes:\n");
+    fprint(fp,WRS("*Classes:\n"));
     for (i=0; i<NUM_CLASSES; i++) 
-      { fprint(fp,"*"); fprint(fp,class_name[i]); fnl(fp); }
+      { fprint(fp,WRS("*")); fprint(fp,class_name[i]); fnl(fp); }
 }
 
 
@@ -980,12 +980,12 @@
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
@@ -1007,9 +1007,9 @@
 	order_next[locus]= ord_next;
 	class[locus]= class_num;
     }
-    fgetln(fp); if (!streq(ln,"*Classes:")) baddata("bad classes");
+    fgetln_(fp); if (!streq(ln,"*Classes:")) baddata("bad classes");
     for (i=0; i<NUM_CLASSES; i++) 
-      { fgetln(fp); strcpy(class_name[i],ln+1); }
+      { fgetln_(fp); strcpy(class_name[i],ln+1); }
 }
 
 
