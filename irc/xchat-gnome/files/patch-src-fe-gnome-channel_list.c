--- src/fe-gnome/channel_list.c.orig	Sun Apr 25 01:14:31 2004
+++ src/fe-gnome/channel_list.c	Wed May  5 00:02:05 2004
@@ -98,6 +98,7 @@
 	GtkSizeGroup *group;
 	GtkTreeSelection *select;
 	int width, height;
+	gchar *title;
 
 	if(sess == NULL)
 		return;
@@ -122,7 +123,7 @@
 	}
 
 	widget = glade_xml_get_widget(win->xml, "window 1");
-	gchar *title = g_strdup_printf("%s Channel List", sess->server->networkname);
+	title = g_strdup_printf("%s Channel List", sess->server->networkname);
 	gtk_window_set_title(GTK_WINDOW(widget), title);
 	g_free(title);
 	g_signal_connect(G_OBJECT(widget), "delete-event", G_CALLBACK(chanlist_delete), win);
