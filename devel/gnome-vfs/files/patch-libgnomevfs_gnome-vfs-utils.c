--- libgnomevfs/gnome-vfs-utils.c.orig	Sat Mar 13 18:57:02 2004
+++ libgnomevfs/gnome-vfs-utils.c	Sat Mar 13 18:51:21 2004
@@ -797,8 +797,10 @@
 	
 #if HAVE_STATVFS
 	statfs_result = statvfs (unescaped_path, &statfs_buffer);
+#define statfs_bsize f_frsize
 #else
 	statfs_result = statfs (unescaped_path, &statfs_buffer);   
+#define statfs_bsize f_bsize
 #endif  
 
 	if (statfs_result != 0) {
@@ -831,7 +833,7 @@
 		}
 	}
 
-	block_size = statfs_buffer.f_bsize; 
+	block_size = statfs_buffer.statfs_bsize; 
 	free_blocks = statfs_buffer.f_bavail;
 
 	*size = block_size * free_blocks;
@@ -859,7 +861,7 @@
 	paths = g_strsplit (gnome_var, ":", 0); 
 
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
-		full_filename = g_strconcat (*temp_paths, "/share/pixmaps/", relative_filename, NULL);
+		full_filename = g_strconcat (*temp_paths, "/share/gnome/pixmaps/", relative_filename, NULL);
 		if (g_file_test (full_filename, G_FILE_TEST_EXISTS)) {
 			g_strfreev (paths);
 			return full_filename;
