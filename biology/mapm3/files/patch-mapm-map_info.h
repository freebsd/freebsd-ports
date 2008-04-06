--- mapm/map_info.h.orig	2008-04-04 20:05:29.000000000 +0000
+++ mapm/map_info.h	2008-03-31 00:14:48.000000000 +0000
@@ -215,7 +215,7 @@
 /***** Chromosome framework, assignment, and placement stuff - chroms.c *****/
 
 extern SAVED_LIST *chromosome;  /* malloced by allocate_mapping_structs() */
-#define chrom2str(x) ((x)>=0 ? chromosome->map_list[x]->map_name : "none")
+#define chrom2str(x) ((x)>=0 ? chromosome->map_list[x]->map_name : WRS("none"))
 bool isa_chrom(); /* args: char *name; int *chrom; side-effected if TRUE */
 #define num_chromosomes (chromosome->num_maps)
 extern int current_chrom; /* set by the sequence command or reset_state() */
