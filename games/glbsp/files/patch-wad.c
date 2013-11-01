--- ./wad.c.orig	2005-09-13 07:19:36.000000000 -0300
+++ ./wad.c	2013-11-01 20:55:13.000000000 -0200
@@ -1632,14 +1632,13 @@
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
