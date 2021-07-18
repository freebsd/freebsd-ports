--- loader/vk_loader_platform.h.orig	2021-04-20 16:45:05 UTC
+++ loader/vk_loader_platform.h
@@ -35,7 +35,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__)
+#if defined(__unix__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__)
 /* Linux-specific common code: */
 
 // Headers:
@@ -120,6 +120,26 @@ static inline char *loader_platform_executable_path(ch
     int ret = proc_pidpath(pid, buffer, size);
     if (ret <= 0) return NULL;
     buffer[ret] = '\0';
+    return buffer;
+}
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#include <sys/sysctl.h>
+static inline char *loader_platform_executable_path(char *buffer, size_t size) {
+    int mib[] = {
+        CTL_KERN,
+#if defined(__NetBSD__)
+        KERN_PROC_ARGS,
+        -1,
+        KERN_PROC_PATHNAME,
+#else
+        KERN_PROC,
+        KERN_PROC_PATHNAME,
+        -1,
+#endif
+    };
+    if (sysctl(mib, sizeof(mib) / sizeof(mib[0]), buffer, &size, NULL, 0) < 0)
+        return NULL;
+
     return buffer;
 }
 #elif defined(__Fuchsia__)
