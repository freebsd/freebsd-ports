--- pixmap.h.orig	2003-02-03 06:52:18.000000000 +0300
+++ pixmap.h	2013-08-28 22:14:20.285227378 +0400
@@ -19,7 +19,7 @@
 void initialize_pixmap (void);
 void resize_pixmap (int new_width, int new_height);
 int pixmap_getpixel (int x, int y);
-inline int pixmap_index (int x, int y);
+int pixmap_index (int x, int y);
 int pixmap_getpixel (int x, int y);
 void pixmap_setpixel (int x, int y, int col);
 void pixmap_hline (int x1, int y1, int x2, int col);
