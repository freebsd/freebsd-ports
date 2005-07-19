--- src/DialogEditor.c.orig	Mon Jul 18 02:45:24 2005
+++ src/DialogEditor.c		Mon Jul 18 02:46:23 2005
@@ -32,6 +32,8 @@
 #define NATIVE_WIN32
 #endif
 
+#include <getopt.h>
+
 #include <gtk/gtk.h>
 #include <gdk/gdk.h>
 #include <gdk/gdkkeysyms.h>
