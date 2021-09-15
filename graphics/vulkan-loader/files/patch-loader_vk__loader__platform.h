--- loader/vk_loader_platform.h.orig	2021-09-15 16:41:50 UTC
+++ loader/vk_loader_platform.h
@@ -37,7 +37,7 @@
 #include "dlopen_fuchsia.h"
 #endif  // defined(__Fuchsia__)
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__)
+#if defined(__unix__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__)
 #include <unistd.h>
 // Note: The following file is for dynamic loading:
 #include <dlfcn.h>
@@ -97,7 +97,7 @@
 // Override layer information
 #define VK_OVERRIDE_LAYER_NAME "VK_LAYER_LUNARG_override"
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__)
+#if defined(__unix__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__)
 /* Linux-specific common code: */
 
 // VK Library Filenames, Paths, etc.:
@@ -168,6 +168,26 @@ static inline char *loader_platform_executable_path(ch
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
