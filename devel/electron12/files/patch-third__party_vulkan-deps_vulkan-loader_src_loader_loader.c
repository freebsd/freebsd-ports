--- third_party/vulkan-deps/vulkan-loader/src/loader/loader.c.orig	2021-04-14 01:15:34 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/loader.c
@@ -253,7 +253,7 @@ void *loader_device_heap_realloc(const struct loader_d
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__FreeBSD__)
 
 static inline bool IsHighIntegrity() {
     return geteuid() != getuid() || getegid() != getgid();
