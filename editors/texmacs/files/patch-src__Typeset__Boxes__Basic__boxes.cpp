--- ./src/Typeset/Boxes/Basic/boxes.cpp.orig	2014-08-28 13:13:07.420709990 -0400
+++ ./src/Typeset/Boxes/Basic/boxes.cpp	2014-08-28 13:13:15.171566990 -0400
@@ -850,7 +850,7 @@
 ******************************************************************************/
 
 void
-make_eps (url name, box b, int dpi) {
+make_eps (url name, box b, int dpi=600) {
   double inch= ((double) dpi * PIXEL);
   double cm  = inch / 2.54;
   SI w= b->x4 - b->x3;
