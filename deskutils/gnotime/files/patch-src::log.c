--- src/log.c.orig	Thu Jul  8 00:23:54 2004
+++ src/log.c	Thu Jul  8 00:24:18 2004
@@ -37,6 +37,8 @@
 	char *filename;
 	GnomeVFSHandle   *handle;
 	GnomeVFSResult    result;
+	GnomeVFSFileSize bytes_written;
+	int rc;
 
 	g_return_val_if_fail (logstr != NULL, FALSE);
 
@@ -67,12 +69,11 @@
 		t = time(NULL);
 
 	/* Translators: Format to use in the gnotime logfile */
-	int rc = strftime (date, sizeof (date), _("%b %d %H:%M:%S"), localtime(&t));
+	rc = strftime (date, sizeof (date), _("%b %d %H:%M:%S"), localtime(&t));
 	if (0 >= rc) strcpy (date, "???");
 
 	/* Append to end of file */
 	gnome_vfs_seek (handle, GNOME_VFS_SEEK_END, 0);
-	GnomeVFSFileSize bytes_written;
 	gnome_vfs_write (handle, date, strlen(date), &bytes_written);
 	gnome_vfs_write (handle, logstr, strlen(logstr), &bytes_written);
 	gnome_vfs_write (handle, "\n", 1, &bytes_written);
