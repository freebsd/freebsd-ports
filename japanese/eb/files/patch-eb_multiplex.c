--- eb/multiplex.c.orig	2010-01-03 12:26:06 UTC
+++ eb/multiplex.c
@@ -876,7 +876,7 @@ ebnet_set_file_path(int file, const char *file_path)
 	return -1;
 
     strncpy(entry->file_path, file_path, EB_MAX_RELATIVE_PATH_LENGTH + 1);
-    *(entry->file_path + EB_MAX_RELATIVE_PATH_LENGTH + 1) = '\0';
+    *(entry->file_path + EB_MAX_RELATIVE_PATH_LENGTH) = '\0';
 
     return 0;
 }
