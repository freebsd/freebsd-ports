--- src/tray-icon.c.orig	Sun Oct 17 00:43:58 2004
+++ src/tray-icon.c	Wed Oct 27 00:08:40 2004
@@ -201,10 +201,10 @@
 	int monitor = gdk_screen_get_monitor_at_window(
 			gtk_widget_get_screen(tv), tv->window);
 	GtkWidget *eventb;
+	char *tooltiptext = NULL;
 	if(tip != NULL) return FALSE;
 
 
-	char *tooltiptext = NULL;
 
 	tooltiptext = tray_get_tooltip_text();
 	gdk_screen_get_monitor_geometry(
