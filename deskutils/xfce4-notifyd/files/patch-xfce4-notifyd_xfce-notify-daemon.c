--- xfce4-notifyd/xfce-notify-daemon.c.orig	2016-09-06 13:19:50 UTC
+++ xfce4-notifyd/xfce-notify-daemon.c
@@ -706,6 +706,7 @@ xfce_notify_daemon_window_size_allocate(
     widget_screen = gtk_widget_get_screen (widget);
     display = gdk_screen_get_display (widget_screen);
     device_manager = gdk_display_get_device_manager (display);
+    pointer = gdk_device_manager_get_client_pointer (device_manager);
 #endif
 
     gdk_device_get_position (pointer, &p_screen, &x, &y);
