--- src/open-location.c.orig	Sat Jul  3 14:33:37 2004
+++ src/open-location.c	Sun Jul 25 17:40:10 2004
@@ -171,9 +171,10 @@
 
 void ol_add_location()
 {
-	if(strlen(gtk_entry_get_text(GTK_ENTRY(glade_xml_get_widget(ol_xml, "entry_stream")))) == 0 ) return;
 	GList *list = NULL;
-	GnomeVFSURI *uri = gnome_vfs_uri_new(gtk_entry_get_text(GTK_ENTRY(glade_xml_get_widget(ol_xml, "entry_stream"))));
+	GnomeVFSURI *uri;
+	if(strlen(gtk_entry_get_text(GTK_ENTRY(glade_xml_get_widget(ol_xml, "entry_stream")))) == 0 ) return;
+	uri = gnome_vfs_uri_new(gtk_entry_get_text(GTK_ENTRY(glade_xml_get_widget(ol_xml, "entry_stream"))));
 	if(uri == NULL)
 	{
 		g_print("Invalid link\n");
