--- src/tX_mouse.h.orig	2011-01-31 06:01:32.000000000 +0900
+++ src/tX_mouse.h	2011-03-18 02:55:38.000000000 +0900
@@ -34,7 +34,7 @@
 #include <X11/extensions/XInput.h>
 #include <X11/keysym.h>
 #include <glib.h>
-#include <gdk/gdk.h>
+#include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
 
 /* Use old gdk keys if the new ones are not yet defined */
