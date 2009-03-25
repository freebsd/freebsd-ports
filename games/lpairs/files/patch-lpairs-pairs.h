--- lpairs/pairs.h.orig	2005-09-27 18:02:58.000000000 +0400
+++ lpairs/pairs.h	2009-03-25 22:04:25.000000000 +0300
@@ -102,10 +102,10 @@
 void draw_button( Pairs *pairs, int map_x, int map_y, int type );
 
 /* get map contents at position */
-inline int get_map_cont( Pairs *pairs, int map_x, int map_y );
+int get_map_cont( Pairs *pairs, int map_x, int map_y );
 
 /* set map contents at position */
-inline void set_map_cont( Pairs *pairs, int map_x, int map_y, int cont );
+void set_map_cont( Pairs *pairs, int map_x, int map_y, int cont );
 
 /* draw all buttons */
 void draw_all_buttons( Pairs *pairs, int type );
