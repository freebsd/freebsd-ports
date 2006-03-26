--- xwin.c.orig	Wed Sep 10 22:55:30 2003
+++ xwin.c	Tue Mar 21 07:05:23 2006
@@ -13,6 +13,7 @@
 #include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <gtk/gtk.h>
 #include <gdk/gdkx.h>
 #include <gdk/gdkkeysyms.h>
@@ -261,7 +262,7 @@
    f=fopen(filename,"w");
    if (!f) return 1;
 
-   image = gdk_image_get(gbackg, 0, 0, width, height);
+   image = gdk_image_get(w, 0, 0, width, height);
    if (!image) {
       fclose(f);
       return 1;
@@ -1378,7 +1379,7 @@
 
       gtk_widget_grab_focus(gdraw1);
 
-      gtk_accel_group_attach(acc, GTK_OBJECT(win1));
+      gtk_window_add_accel_group(GTK_WINDOW(win1), acc);
 
       ggc = gdk_gc_new(w->window);
 
@@ -1478,7 +1479,7 @@
 
       gtk_widget_grab_focus(gdraw2);
 
-      gtk_accel_group_attach(acc, GTK_OBJECT(win2));
+      gtk_window_add_accel_group(GTK_WINDOW(win2), acc);
 
       ggc2 = gdk_gc_new(w->window);
 
