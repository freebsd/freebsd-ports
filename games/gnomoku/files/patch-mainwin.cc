--- mainwin.cc.orig	Sat Oct 16 11:58:08 2004
+++ mainwin.cc	Sat Oct 16 11:58:36 2004
@@ -93,9 +93,9 @@
     // Table
     Gtk::Table* table = new Gtk::Table (rows, cols, true);
     Point *p;
-    tbl = new (Point**)[rows];
+    tbl = new Point**[rows];
     for (int y=0; y<rows; y++) {
-	tbl[y] = new (Point*)[cols];
+	tbl[y] = new Point*[cols];
 	for (int x=0; x<cols; x++) {
 	    p = new Point(y,x);
 	    tbl[y][x] = p;
