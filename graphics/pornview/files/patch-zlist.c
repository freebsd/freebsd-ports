--- src/support/widgets/zlist.c.orig	2002-12-13 11:52:56.000000000 +0100
+++ src/support/widgets/zlist.c	2009-04-19 13:58:56.000000000 +0200
@@ -634,7 +634,8 @@
 					   CELL_X_FROM_COL (list, j), area->y,
 					   list->cell_x_pad, area->height);
 
-		cell = ZLIST_CELL_FROM_INDEX (list, idx);
+		if (idx < list->cell_count)
+	 		cell = ZLIST_CELL_FROM_INDEX (list, idx);
 
 		cell_area.x = CELL_X_FROM_COL (list, j) + list->cell_x_pad;
 		cell_area.y = CELL_Y_FROM_ROW (list, i) + list->cell_y_pad;
