--- src/trayicon.c.orig	2012-04-07 21:56:11 UTC
+++ src/trayicon.c
@@ -31,6 +31,8 @@ const char *tray_image_stocks[] = {
 	 "audio-volume-high"
  	 };
 
+GtkStatusIcon *tray_icon; 
+GdkPixbuf *tray_pixbufs[4]; 
  
 GtkStatusIcon *create_tray_icon() 
 {
@@ -49,6 +51,8 @@ GtkStatusIcon *create_tray_icon() 
 	
 	gtk_status_icon_set_visible(tray_icon, TRUE);
 
+GtkStatusIcon *tray_icon;
+GdkPixbuf *tray_pixbufs[4];
 
 	return tray_icon;
 }
@@ -157,4 +161,4 @@ void update_tray_image()
 
 	g_sprintf(volchar, "%i\%%", vol);
 	if (opt_show_tooltip) gtk_status_icon_set_tooltip_text(tray_icon, volchar);
-}
\ No newline at end of file
+}
