--- src/export.c.orig	Thu Jul  8 00:14:29 2004
+++ src/export.c	Thu Jul  8 00:15:18 2004
@@ -124,12 +124,14 @@
 export_really (GtkWidget *widget, export_format_t *xp)
 {
 	gboolean rc;
+	GnomeVFSURI *parsed_uri;
+	gboolean exists;
+	GnomeVFSResult result;
 
 	xp->uri = gtk_file_selection_get_filename (xp->picker);
 
-	GnomeVFSURI *parsed_uri;
 	parsed_uri = gnome_vfs_uri_new (xp->uri);
-	gboolean exists = gnome_vfs_uri_exists (parsed_uri);
+	exists = gnome_vfs_uri_exists (parsed_uri);
 	if (exists) 
 	{
 		GtkWidget *w;
@@ -144,14 +146,14 @@
 		if (0 == gnome_dialog_run (GNOME_DIALOG (w))) goto done;
 	}
 
-	GnomeVFSResult result;
 	result = gnome_vfs_create (&xp->handle, xp->uri, GNOME_VFS_OPEN_WRITE,
 	                 FALSE, 0644);
 	if (GNOME_VFS_OK != result)
 	{
 		char *s;
+		GtkWidget *w;
 		s = g_strdup_printf (_("File %s dould not be opened"), xp->uri);
-		GtkWidget *w = gnome_error_dialog (s);
+		w = gnome_error_dialog (s);
 		gnome_dialog_set_parent (GNOME_DIALOG (w), GTK_WINDOW (xp->picker));
 		g_free (s);
 		goto done;
