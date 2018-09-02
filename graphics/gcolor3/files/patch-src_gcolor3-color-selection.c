https://github.com/Hjdskes/gcolor3/commit/8d89081a8e13749f5a9051821114bc5fe814eaf3

--- src/gcolor3-color-selection.c.orig	2018-09-02 12:48:50 UTC
+++ src/gcolor3-color-selection.c
@@ -36,7 +36,10 @@
 
 #include <math.h>
 #include <string.h>
+#include <gdk/gdk.h>
+#ifdef GDK_WINDOWING_WAYLAND
 #include <gdk/gdkwayland.h>
+#endif
 #include <gtk/gtk.h>
 #include <glib/gi18n.h>
 
