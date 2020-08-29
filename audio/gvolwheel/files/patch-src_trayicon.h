--- src/trayicon.h.orig	2011-06-04 12:27:58 UTC
+++ src/trayicon.h
@@ -2,8 +2,8 @@
 #include <glib/gstdio.h>
 #include <glib/gi18n-lib.h>
 
-GtkStatusIcon *tray_icon; 
-GdkPixbuf *tray_pixbufs[4]; 
+extern GtkStatusIcon *tray_icon; 
+extern GdkPixbuf *tray_pixbufs[4]; 
 
 GtkStatusIcon* create_tray_icon();
 gboolean tray_icon_recreate(gpointer data);
@@ -12,4 +12,4 @@ void on_tray_icon_scroll (GtkWidget *widget, GdkEventS
 void on_tray_icon_click(GtkWidget *widget, GdkEventButton *event, gpointer user_data);
 void on_tray_icon_press(GtkWidget *widget, GdkEventButton *event, gpointer user_data);
 void update_tray_image();
-void load_pixbufs();
\ No newline at end of file
+void load_pixbufs();
