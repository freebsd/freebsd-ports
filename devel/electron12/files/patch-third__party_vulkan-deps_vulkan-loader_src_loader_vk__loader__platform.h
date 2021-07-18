--- third_party/vulkan-deps/vulkan-loader/src/loader/vk_loader_platform.h.orig	2021-04-14 01:15:34 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/vk_loader_platform.h
@@ -35,7 +35,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__FreeBSD__)
 /* Linux-specific common code: */
 
 // Headers:
@@ -52,6 +52,12 @@
 #include <stdlib.h>
 #include <libgen.h>
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/user.h>
+#include <libutil.h>
+#endif
+
 // VK Library Filenames, Paths, etc.:
 #define PATH_SEPARATOR ':'
 #define DIRECTORY_SYMBOL '/'
@@ -120,6 +126,17 @@ static inline char *loader_platform_executable_path(ch
     int ret = proc_pidpath(pid, buffer, size);
     if (ret <= 0) return NULL;
     buffer[ret] = '\0';
+    return buffer;
+}
+#elif defined(__FreeBSD__)
+static inline char *loader_platform_executable_path(char *buffer, size_t size) {
+    pid_t pid = getpid();
+    struct kinfo_proc *p = kinfo_getproc(pid);
+    if (p == NULL) return NULL;
+    size_t len = strnlen(p->ki_comm, size - 1);
+    memcpy(buffer, p->ki_comm, len);
+    buffer[len] = '\0';
+    free(p);
     return buffer;
 }
 #elif defined(__Fuchsia__)
