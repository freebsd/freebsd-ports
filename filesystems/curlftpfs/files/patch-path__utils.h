--- path_utils.h.orig	2007-11-20 19:27:58 UTC
+++ path_utils.h
@@ -6,4 +6,11 @@ char* get_full_path(const char* path);
 char* get_fulldir_path(const char* path);
 char* get_dir_path(const char* path);
 
+/*
+ * Transforms UNIX path to RFC3986 encoded path
+ * (CURLOPT_URL accepts only such paths)
+ */
+char* path_to_uri(const char* path);
+void free_uri(char* path);
+
 #endif   /* __CURLFTPFS_PATH_UTILS_H__ */
