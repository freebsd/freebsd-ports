--- third_party/vulkan-loader/src/loader/vk_loader_platform.h.orig	2026-08-24 20:59:34 UTC
+++ third_party/vulkan-loader/src/loader/vk_loader_platform.h
@@ -360,7 +360,15 @@ static inline char *loader_platform_executable_path(ch
 
     return buffer;
 }
-#elif defined(__Fuchsia__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
+static inline char *loader_platform_executable_path(char *buffer, size_t size) {
+    if ((buffer = getenv("CHROME_EXE_PATH")) != NULL)
+        return buffer;
+    else
+        buffer = "/usr/local/chrome/chrome";
+  return buffer;
+}
+#elif defined(__Fuchsia__)
 static inline char *loader_platform_executable_path(char *buffer, size_t size) { return NULL; }
 #elif defined(__QNX__)
 
