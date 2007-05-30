--- widget.c.orig	Wed May 30 16:24:53 2007
+++ widget.c	Wed May 30 16:28:12 2007
@@ -124,11 +124,11 @@
 extern Pixmap acts_pm;
 void (*notify_func)();
 
+Pixmap get_pixmap(char *bits, int width, int height, boolean inv);
+
 void init_widgets(notify)
 void (*notify)();
 {
-    extern Pixmap get_pixmap();
-
     numb = nums = numc = numm = cur_type = cur_num = 0;
     key_active = cur_but = -1;
     scan_flag = FALSE;
