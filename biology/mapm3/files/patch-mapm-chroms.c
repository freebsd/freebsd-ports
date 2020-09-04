--- mapm/chroms.c.orig	1993-02-09 16:35:02 UTC
+++ mapm/chroms.c
@@ -909,7 +909,7 @@ FILE *fp;
         write_map(fp, chromosome->map_list[i]);
     }
    
-    fprint(fp,"*Assignments and Placements:\n");
+    fprint(fp,WRS("*Assignments and Placements:\n"));
     for (locus=0; locus< raw.num_markers; locus++) {
         sf(ps,"*%-8s %2d",raw.locus_name[locus],assignment[locus]->status); 
 	fpr(fp);
@@ -943,7 +943,7 @@ FILE *fp;
     MAP  *map;
 
     /* chromosomes */
-    fgetln(fp);
+    fgetln_(fp);
     stoken(&ln,sREQUIRED,word);
     if (!streq(word,"*Chromosomes:") || !itoken(&ln,iREQUIRED,&num_chroms)) {
         baddata("error finding *Chromosomes:");
@@ -957,7 +957,7 @@ FILE *fp;
         baddata("listed number of chromosomes and actual number do not agree");
     }
 
-    fgetln(fp);
+    fgetln_(fp);
     if (!streq(ln,"*Assignments and Placements:"))
         baddata("error finding *Assignments and Placements:");
     for (locus=0; locus < raw.num_markers; locus++) {
