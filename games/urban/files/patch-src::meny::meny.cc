--- src/meny/meny.cc.orig	Fri Jul  2 02:23:30 1999
+++ src/meny/meny.cc	Sun Jan 25 23:17:19 2004
@@ -124,7 +124,7 @@
 	return 1;
 }
 /*****************************************************************************************/
-int Do_Menu(char *text, int num_items, int pos = 1) {
+int Do_Menu(char *text, int num_items, int pos) {
 	PALETTE pal;
 	UrbanFont m(LARGE_FONT);
         m.SetScale(65);
