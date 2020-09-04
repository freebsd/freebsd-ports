--- mapm/map_info.h.orig	1993-02-09 16:35:06 UTC
+++ mapm/map_info.h
@@ -215,7 +215,7 @@ typedef struct {  /* working data for place cmd and ex
 /***** Chromosome framework, assignment, and placement stuff - chroms.c *****/
 
 extern SAVED_LIST *chromosome;  /* malloced by allocate_mapping_structs() */
-#define chrom2str(x) ((x)>=0 ? chromosome->map_list[x]->map_name : "none")
+#define chrom2str(x) ((x)>=0 ? chromosome->map_list[x]->map_name : WRS("none"))
 bool isa_chrom(); /* args: char *name; int *chrom; side-effected if TRUE */
 #define num_chromosomes (chromosome->num_maps)
 extern int current_chrom; /* set by the sequence command or reset_state() */
