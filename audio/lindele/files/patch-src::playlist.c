--- src/playlist.c.orig	Mon Jul 26 22:15:56 2004
+++ src/playlist.c	Mon Jul 26 22:16:13 2004
@@ -458,10 +458,10 @@
 void
 popup_context_menu(GtkWidget *widget, GdkEventButton *event)
 {
-    g_printf("entry into popup_context_menu\n");
     GtkWidget *menu,*menuitem;
     int button, event_time;
     
+    g_printf("entry into popup_context_menu\n");
     menu = gtk_menu_new ();
     g_signal_connect (menu,"deactivate",G_CALLBACK(gtk_widget_destroy),NULL);
     
