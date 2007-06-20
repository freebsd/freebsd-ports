--- src/window_size.c.orig	Wed Jun 21 00:47:14 1995
+++ src/window_size.c	Fri Jun 15 00:33:44 2007
@@ -28,8 +28,8 @@
 /* static variables */
 static Widget resize_main_window_shell = NULL;
 static Widget resize_main_window_dialog = NULL;
-static Widget explicit_x_size_scale = NULL;
-static Widget explicit_y_size_scale = NULL;
+Widget explicit_x_size_scale = NULL;
+Widget explicit_y_size_scale = NULL;
 
 /*ARGSUSED*/
 void window_size_cb(
