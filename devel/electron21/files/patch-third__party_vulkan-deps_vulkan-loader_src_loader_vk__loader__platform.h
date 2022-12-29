--- third_party/vulkan-deps/vulkan-loader/src/loader/vk_loader_platform.h.orig	2022-08-31 12:19:35 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/vk_loader_platform.h
@@ -43,7 +43,7 @@
 #include "dlopen_fuchsia.h"
 #endif  // defined(__Fuchsia__)
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <unistd.h>
 // Note: The following file is for dynamic loading:
 #include <dlfcn.h>
@@ -98,7 +98,7 @@
 #define LAYERS_PATH_ENV "VK_LAYER_PATH"
 #define ENABLED_LAYERS_ENV "VK_INSTANCE_LAYERS"
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 /* Linux-specific common code: */
 
 // VK Library Filenames, Paths, etc.:
@@ -219,7 +219,7 @@ static inline void loader_platform_thread_once_fn(pthr
 
 #endif
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 
 // File IO
 static inline bool loader_platform_file_exists(const char *path) {
@@ -277,6 +277,15 @@ static inline char *loader_platform_executable_path(ch
     if (sysctl(mib, sizeof(mib) / sizeof(mib[0]), buffer, &size, NULL, 0) < 0) {
         return NULL;
     }
+
+    return buffer;
+}
+#elif defined(__OpenBSD__)
+static inline char *loader_platform_executable_path(char *buffer, size_t size) {
+    if ((buffer = getenv("CHROME_EXE_PATH")) != NULL)
+        return buffer;
+    else
+        buffer = "/usr/local/chrome/chrome";
 
     return buffer;
 }
