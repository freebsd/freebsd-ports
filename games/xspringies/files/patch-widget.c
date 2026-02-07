--- widget.c.orig	1995-11-11 12:47:22.000000000 +0900
+++ widget.c	2011-08-19 07:11:46.000000000 +0900
@@ -124,7 +124,7 @@
 extern Pixmap acts_pm;
 void (*notify_func)();
 
-Pixmap get_pixmap();
+Pixmap get_pixmap(char *bits, int width, int height, boolean inv);
 
 void init_widgets(notify)
 void (*notify)();
