--- libgnomevfs/gnome-vfs-utils.c.orig	Fri Apr 16 06:43:05 2004
+++ libgnomevfs/gnome-vfs-utils.c	Mon Apr 19 15:41:47 2004
@@ -797,7 +797,9 @@
 	
 #if HAVE_STATVFS
 	statfs_result = statvfs (unescaped_path, &statfs_buffer);
+#define statfs_bsize f_frsize
 #else
+#define statfs_bsize f_bsize
 #if STATFS_ARGS == 2
 	statfs_result = statfs (unescaped_path, &statfs_buffer);   
 #elif STATFS_ARGS == 4
@@ -838,7 +840,7 @@
 	}
 #endif
 
-	block_size = statfs_buffer.f_bsize; 
+	block_size = statfs_buffer.statfs_bsize; 
 	free_blocks = statfs_buffer.f_bavail;
 
 	*size = block_size * free_blocks;
@@ -866,7 +868,7 @@
 	paths = g_strsplit (gnome_var, ":", 0); 
 
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
-		full_filename = g_strconcat (*temp_paths, "/share/pixmaps/", relative_filename, NULL);
+		full_filename = g_strconcat (*temp_paths, "/share/gnome/pixmaps/", relative_filename, NULL);
 		if (g_file_test (full_filename, G_FILE_TEST_EXISTS)) {
 			g_strfreev (paths);
 			return full_filename;
