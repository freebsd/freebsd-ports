--- src/Typeset/Boxes/Basic/rubber.gen.cc.orig	Sun Nov 24 21:02:01 2002
+++ src/Typeset/Boxes/Basic/rubber.gen.cc	Sun Nov 24 21:02:38 2002
@@ -185,7 +185,7 @@
 /*****************************************************************************/
 
 box
-empty_box (path ip, int x1=0, int y1=0, int x2=0, int y2=0) {
+empty_box (path ip, int x1, int y1, int x2, int y2) {
   return new empty_box_rep (ip, x1, y1, x2, y2);
 }
 
