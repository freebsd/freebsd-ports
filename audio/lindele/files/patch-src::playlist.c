--- src/playlist.c.orig	Tue Jan 18 02:25:55 2005
+++ src/playlist.c	Tue Jan 18 02:25:57 2005
@@ -458,7 +458,6 @@
 void
 popup_context_menu(GtkWidget *widget, GdkEventButton *event)
 {
-    g_printf("entry into popup_context_menu\n");
     GtkWidget *menu,*menuitem;
     int button, event_time;
     
