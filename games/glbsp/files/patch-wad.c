--- wad.c.orig	2005-09-13 10:19:36 UTC
+++ wad.c
@@ -1632,14 +1632,13 @@ void ReportOverflows(boolean_g hard)
 void ReportV5Switches(void)
 {
   lump_t *cur;
+  int saw_zdbsp = FALSE;
 
   PrintMsg(
     "V5 FORMAT UPGRADES.  The following levels require a Doom port\n"
     "which supports V5 GL-Nodes, otherwise they will fail (or crash).\n\n"
   );
 
-  int saw_zdbsp = FALSE;
-
   for (cur=wad.dir_head; cur; cur=cur->next)
   {
     level_t *lev = cur->lev_info;
