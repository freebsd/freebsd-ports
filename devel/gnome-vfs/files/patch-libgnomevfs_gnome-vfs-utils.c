--- libgnomevfs/gnome-vfs-utils.c.orig	Mon Aug 16 11:11:09 2004
+++ libgnomevfs/gnome-vfs-utils.c	Mon Aug 16 11:11:16 2004
@@ -871,7 +871,7 @@
 	paths = g_strsplit (gnome_var, ":", 0); 
 
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
-		full_filename = g_strconcat (*temp_paths, "/share/pixmaps/", relative_filename, NULL);
+		full_filename = g_strconcat (*temp_paths, "/share/gnome/pixmaps/", relative_filename, NULL);
 		if (g_file_test (full_filename, G_FILE_TEST_EXISTS)) {
 			g_strfreev (paths);
 			return full_filename;
