--- libgnomevfs/gnome-vfs-mime.c.orig	Sat Mar 19 18:59:45 2005
+++ libgnomevfs/gnome-vfs-mime.c	Sat Mar 19 19:02:24 2005
@@ -167,7 +167,9 @@
 	GnomeVFSResult result = GNOME_VFS_OK;
 	const char *mime_type;
 
+	G_LOCK (mime_mutex);
 	max_extents = xdg_mime_get_max_buffer_extents ();
+	G_UNLOCK (mime_mutex);
 	max_extents = CLAMP (max_extents, 0, MAX_SNIFF_BUFFER_ALLOWED);
 
 	if (!buffer->read_whole_file) {
@@ -592,7 +594,9 @@
 	g_return_val_if_fail (a != NULL, FALSE);
 	g_return_val_if_fail (b != NULL, FALSE);
 
+	G_LOCK (mime_mutex);
 	xdg_mime_mime_type_equal (a, b);
+	G_UNLOCK (mime_mutex);
 
 	return FALSE;
 }
@@ -626,8 +630,13 @@
 
 	if (gnome_vfs_mime_type_is_equal (mime_type, base_mime_type)) {
 		return GNOME_VFS_MIME_IDENTICAL;
-	} else if (xdg_mime_mime_type_subclass (mime_type, base_mime_type)) {
-		return GNOME_VFS_MIME_PARENT;
+	} else {
+		G_LOCK (mime_mutex);
+		if (xdg_mime_mime_type_subclass (mime_type, base_mime_type)) {
+			G_UNLOCK (mime_mutex);
+			return GNOME_VFS_MIME_PARENT;
+		}
+		G_UNLOCK (mime_mutex);
 	}
 
 	return GNOME_VFS_MIME_UNRELATED;
