--- xwin.c.orig	Fri Mar 17 20:50:07 2006
+++ xwin.c	Fri Mar 17 20:50:52 2006
@@ -13,6 +13,7 @@
 #include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <gtk/gtk.h>
 #include <gdk/gdkx.h>
 #include <gdk/gdkkeysyms.h>
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
 
