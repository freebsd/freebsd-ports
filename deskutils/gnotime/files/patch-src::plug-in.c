--- src/plug-in.c.orig	Thu Jul  8 00:26:35 2004
+++ src/plug-in.c	Thu Jul  8 00:27:06 2004
@@ -96,6 +96,8 @@
 {
 	const char *title, *path, *tip;
 	NewPluginDialog *dlg = data;
+	GnomeVFSURI *parsed_uri;
+	gboolean exists;
 
 	/* Get the dialog contents */
 	title = gtk_entry_get_text (dlg->plugin_name);
@@ -103,9 +105,8 @@
 	tip = gtk_entry_get_text (dlg->plugin_tooltip);
 
 	/* Do a basic sanity check */
-	GnomeVFSURI *parsed_uri;
 	parsed_uri = gnome_vfs_uri_new (path);
-	gboolean exists = gnome_vfs_uri_exists (parsed_uri);
+	exists = gnome_vfs_uri_exists (parsed_uri);
 	gnome_vfs_uri_unref (parsed_uri);
 	if (!exists)
 	{
