--- ./source/unix/gtkui/gtkui.h.orig	2016-01-09 18:34:38 -0500
+++ ./source/unix/gtkui/gtkui.h	2016-01-15 11:34:58 -0500
@@ -8,7 +8,6 @@
 #elif _APPLE
 #else
 #include <gdk/gdkx.h>
-#include <gdk/gdkwayland.h>
 #endif
 
 void gtkui_init(int argc, char *argv[]);
