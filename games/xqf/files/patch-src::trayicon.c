--- src/trayicon.c.orig	Sun Jun 20 03:30:35 2004
+++ src/trayicon.c	Wed Dec  1 07:16:59 2004
@@ -792,6 +792,8 @@
     }
   }  else {
   
+      GdkWindow *gdkwin;
+
       icon->box=gtk_event_box_new ();
       gtk_container_add(GTK_CONTAINER(icon), icon->box);
       
@@ -801,8 +803,6 @@
       
       gtk_widget_show (icon->image);
       gtk_widget_show(icon->box);
-      
-      GdkWindow *gdkwin;
       
       gdkwin = gdk_window_lookup (icon->manager_window);
       gdk_window_add_filter (gdkwin, egg_tray_icon_manager_filter, icon);
