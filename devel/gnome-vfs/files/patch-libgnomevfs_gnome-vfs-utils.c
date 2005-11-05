--- libgnomevfs/gnome-vfs-utils.c.orig	Thu Sep 15 07:02:53 2005
+++ libgnomevfs/gnome-vfs-utils.c	Sat Oct 22 02:12:32 2005
@@ -839,6 +839,7 @@ gnome_vfs_icon_path_from_filename (const
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
 		full_filename = g_build_filename (*temp_paths,
 						  "share",
+						  "gnome",
 						  "pixmaps",
 						  relative_filename,
 						  NULL);
@@ -1991,9 +1992,14 @@ _gnome_vfs_uri_resolve_all_symlinks_uri 
 			resolved_uri = gnome_vfs_uri_resolve_relative (new_uri,
 								       info->symlink_name);
 			if (*p != 0) {
+				gnome_vfs_uri_unref (new_uri);
+
+				new_uri = gnome_vfs_uri_append_string (resolved_uri, p);
+
 				gnome_vfs_uri_unref (uri);
-				uri = gnome_vfs_uri_append_string (resolved_uri, p);
 				gnome_vfs_uri_unref (resolved_uri);
+
+				uri = gnome_vfs_uri_ref (new_uri);
 			} else {
 				gnome_vfs_uri_unref (uri);
 				uri = resolved_uri;
