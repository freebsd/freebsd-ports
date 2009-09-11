--- wordrec/render.cpp.orig	2009-09-11 05:04:06.000000000 -0400
+++ wordrec/render.cpp	2009-09-11 05:07:37.000000000 -0400
@@ -108,13 +108,13 @@
  * that was supplied as input.
  **********************************************************************/
 void render_edgepts(void *window, EDGEPT *edgept, C_COL color) {
+  if (!edgept)
+    return;
+
   float x = edgept->pos.x;
   float y = edgept->pos.y;
   EDGEPT *this_edge = edgept;
 
-  if (!edgept)
-    return;
-
   c_line_color_index(window, color);
   c_move(window, x, y);
   do {
