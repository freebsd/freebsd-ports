--- grecord/gsr-window.c.orig	Fri Dec 24 15:16:11 2004
+++ grecord/gsr-window.c	Fri Dec 24 15:16:13 2004
@@ -29,7 +29,7 @@
 #include <unistd.h>
 
 #include <gnome.h>
-#include <libgnomevfs/gnome-vfs-utils.h>
+#include <libgnomevfs/gnome-vfs.h>
 #include <gconf/gconf-client.h>
 #include <gst/gst.h>
 #include <gst/gconf/gconf.h>
@@ -475,16 +475,41 @@
 {
 	GSRWindowPrivate *priv;
         GMAudioProfile *profile;
-	char *tmp;
+	char *tmp, *src;
+	GnomeVFSURI *src_uri, *dst_uri;
 	
 	priv = window->priv;
 	
         profile = gm_audio_profile_choose_get_active (priv->profile);
 
-	tmp = g_strdup_printf ("%s.%s", name,
+	tmp = g_strdup_printf ("file://%s.%s", name,
 			       gm_audio_profile_get_extension (profile));
-	rename (priv->record_filename, tmp);
-	g_free (tmp);		
+	src = g_strdup_printf ("file://%s", priv->record_filename);
+	src_uri = gnome_vfs_uri_new (src);
+	dst_uri = gnome_vfs_uri_new (tmp);
+	g_free (src);
+	g_free (tmp);
+	if (src_uri && dst_uri) {
+		GnomeVFSResult result;
+		result = gnome_vfs_xfer_uri (src_uri, dst_uri,
+			GNOME_VFS_XFER_DEFAULT,
+			GNOME_VFS_XFER_ERROR_MODE_ABORT,
+			GNOME_VFS_XFER_OVERWRITE_MODE_REPLACE,
+			NULL, NULL);
+		if (result == GNOME_VFS_OK) {
+			char *title, *short_name;
+			priv->filename = g_strdup_printf ("%s.%s",
+				name, gm_audio_profile_get_extension (profile));
+			short_name = g_path_get_basename (priv->filename);
+			title = g_strdup_printf ("%s - Sound Recorder",
+				short_name);
+			gtk_window_set_title (GTK_WINDOW (window), title);
+			priv->dirty = FALSE;
+			g_free (title);
+		}
+		gnome_vfs_uri_unref (src_uri);
+		gnome_vfs_uri_unref (dst_uri);
+	}
 }
 
 static void
