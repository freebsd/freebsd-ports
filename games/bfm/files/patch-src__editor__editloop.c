--- ./src/editor/editloop.c.orig	Thu Apr 14 12:09:25 2005
+++ ./src/editor/editloop.c	Thu Mar 22 10:50:07 2007
@@ -2043,7 +2043,7 @@
 ---------------------------------------------------------------------------*/
 
 // Deletes all units, changes player properties and fills map with grass.
-local int EditorClearMap(void)
+int EditorClearMap(void)
 {
 	Unit* unit;
 	int mz;
