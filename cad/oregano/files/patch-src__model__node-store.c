--- src/model/node-store.c.orig	Wed May 24 14:16:30 2006
+++ src/model/node-store.c	Wed May 24 19:07:00 2006
@@ -432,9 +432,9 @@
 			SheetPos w_pos, w_length;
 			gboolean can_join;
 			GSList *nodes;
+			gdouble _x1, _x2, _y1, _y2;
 
 			wire_get_pos_and_length (ipoint->wire, &w_pos, &w_length);
-			gdouble _x1, _x2, _y1, _y2;
 
 			_x1 = w_pos.x;
 			_y1 = w_pos.y;
@@ -481,9 +481,9 @@
 			SheetPos w_pos, w_length;
 			gboolean can_join;
 			GSList *nodes;
+			gdouble _x1, _x2, _y1, _y2;
 
 			wire_get_pos_and_length (ipoint->wire, &w_pos, &w_length);
-			gdouble _x1, _x2, _y1, _y2;
 
 			_x1 = w_pos.x;
 			_y1 = w_pos.y;
