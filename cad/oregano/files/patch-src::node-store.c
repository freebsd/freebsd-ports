--- src/node-store.c.orig	Tue Oct 12 04:04:27 2004
+++ src/node-store.c	Fri Nov 26 18:05:48 2004
@@ -431,9 +431,10 @@
 
 		if (IS_EQ (x1, x2) && ((ipoint->pos.y == y1) || (ipoint->pos.y == y2))) {
 			SheetPos w_pos, w_length;
-			wire_get_pos_and_length (ipoint->wire, &w_pos, &w_length);
 			gdouble _x1, _x2, _y1, _y2;
 
+			wire_get_pos_and_length (ipoint->wire, &w_pos, &w_length);
+
 			_x1 = w_pos.x;
 			_y1 = w_pos.y;
 			_x2 = x1 + w_length.x;
@@ -457,8 +458,9 @@
 			}
 		} else if (IS_EQ (y1, y2) && ((ipoint->pos.x == x1) || (ipoint->pos.x == x2))) {
 			SheetPos w_pos, w_length;
-			wire_get_pos_and_length (ipoint->wire, &w_pos, &w_length);
 			gdouble _x1, _x2, _y1, _y2;
+
+			wire_get_pos_and_length (ipoint->wire, &w_pos, &w_length);
 
 			_x1 = w_pos.x;
 			_y1 = w_pos.y;
