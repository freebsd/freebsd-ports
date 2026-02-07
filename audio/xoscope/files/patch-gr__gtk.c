--- gr_gtk.c.orig	2020-08-24 15:25:56 UTC
+++ gr_gtk.c
@@ -28,6 +28,9 @@
 
 #include "xoscope.rc.h"
 
+extern GtkWidget *glade_window;
+extern GtkWidget *menubar;
+
 char my_filename[FILENAME_MAX] = "";
 GdkFont *font;
 char fontname[80] = DEF_FX;
