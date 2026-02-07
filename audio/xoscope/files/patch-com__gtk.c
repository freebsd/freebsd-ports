--- com_gtk.c.orig	2020-08-24 15:23:20 UTC
+++ com_gtk.c
@@ -19,6 +19,8 @@
 #include "com_gtk.h"
 
 GdkPixmap *pixmap = NULL;
+extern GtkWidget *menubar;
+extern GtkWidget *glade_window;
 int fixing_widgets = 0;
 
 /* emulate several libsx function in GTK */
