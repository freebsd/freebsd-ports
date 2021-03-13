--- src/trayicon.c.orig	2014-11-02 00:43:18 UTC
+++ src/trayicon.c
@@ -726,6 +726,7 @@ static void egg_tray_icon_update_manager_window (EggTr
 			icon->ready=TRUE;
 		}
 	} else {
+		GdkWindow *gdkwin;
 
 		icon->box=gtk_event_box_new ();
 		gtk_container_add(GTK_CONTAINER(icon), icon->box);
@@ -736,8 +737,6 @@ static void egg_tray_icon_update_manager_window (EggTr
 
 		gtk_widget_show (icon->image);
 		gtk_widget_show(icon->box);
-
-		GdkWindow *gdkwin;
 
 		gdkwin = gdk_window_lookup (icon->manager_window);
 		gdk_window_add_filter (gdkwin, egg_tray_icon_manager_filter, icon);
