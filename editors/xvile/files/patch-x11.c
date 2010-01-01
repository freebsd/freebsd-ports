--- x11.c.orig	2009-12-31 14:32:20.000000000 +0100
+++ x11.c	2009-12-31 14:33:53.000000000 +0100
@@ -2180,10 +2180,15 @@
 static GC
 get_color_gc(int n, Boolean normal)
 {
-    ColorGC *data = (normal
-		     ? &(cur_win->fore_color[n])
-		     : &(cur_win->back_color[n]));
+    ColorGC *data;
 
+   assert(n >= 0 && n < NCOLORS);
+
+   if (n < 0 || n > NCOLORS)
+      n = 0;                  /* shouldn't happen */
+   data = (normal
+          ? &(cur_win->fore_color[n])
+          : &(cur_win->back_color[n]));
     if (cur_win->screen_depth == 1) {
 	data->gc = (normal
 		    ? cur_win->textgc
