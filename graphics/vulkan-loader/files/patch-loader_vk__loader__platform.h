--- loader/vk_loader_platform.h.orig	2021-11-03 16:21:38 UTC
+++ loader/vk_loader_platform.h
@@ -156,7 +156,7 @@ static inline bool loader_platform_is_path_absolute(co
 
 static inline char *loader_platform_dirname(char *path) { return dirname(path); }
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__)
 
 // find application path + name. Path cannot be longer than 1024, returns NULL if it is greater than that.
 static inline char *loader_platform_executable_path(char *buffer, size_t size) {
