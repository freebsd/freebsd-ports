--- src/fe-gnome/channel_list.c.orig	Wed Oct 13 10:27:41 2004
+++ src/fe-gnome/channel_list.c	Wed Oct 13 10:28:10 2004
@@ -118,6 +118,7 @@
 	GtkSizeGroup *group;
 	GtkTreeSelection *select;
 	int width, height;
+	gchar *title;
 
 	if (sess == NULL)
 		return;
@@ -142,7 +143,7 @@
 	}
 
 	widget = glade_xml_get_widget (win->xml, "window 1");
-	gchar *title = g_strdup_printf ("%s Channel List", get_network (sess));
+	title = g_strdup_printf ("%s Channel List", get_network (sess));
 	gtk_window_set_title (GTK_WINDOW (widget), title);
 	g_free (title);
 	g_signal_connect (G_OBJECT (widget), "delete-event", G_CALLBACK (chanlist_delete), win);
