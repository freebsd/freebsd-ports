--- src/Typeset/Boxes/Basic/boxes.cpp.orig	2015-12-10 11:04:15 UTC
+++ src/Typeset/Boxes/Basic/boxes.cpp
@@ -868,7 +868,7 @@ attach_dip (tree ref, path dip) {
 ******************************************************************************/
 
 void
-make_eps (url name, box b, int dpi) {
+make_eps (url name, box b, int dpi=600) {
   double inch= ((double) dpi * PIXEL);
   double cm  = inch / 2.54;
   SI w= b->x4 - b->x3;
