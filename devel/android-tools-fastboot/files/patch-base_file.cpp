--- base/file.cpp.orig	2019-07-17 19:54:09 UTC
+++ base/file.cpp
@@ -20,6 +20,7 @@
 #include <fcntl.h>
 #include <ftw.h>
 #include <libgen.h>
+#include <limits.h> // PATH_MAX for GCC
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -35,6 +36,9 @@
 #if defined(__APPLE__)
 #include <mach-o/dyld.h>
 #endif
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
 #if defined(_WIN32)
 #include <direct.h>
 #include <windows.h>
@@ -421,6 +425,23 @@ std::string GetExecutablePath() {
   if (result == 0 || result == sizeof(path) - 1) return "";
   path[PATH_MAX - 1] = 0;
   return path;
+#elif defined(KERN_PROC_PATHNAME)
+  char path[PATH_MAX + 1];
+  size_t path_len = sizeof(path);
+  int mib[] = {
+    CTL_KERN,
+#if defined(__NetBSD__)
+    KERN_PROC_ARGS,
+    -1,
+    KERN_PROC_PATHNAME,
+#else
+    KERN_PROC,
+    KERN_PROC_PATHNAME,
+    -1,
+#endif
+  };
+  int rc = sysctl(mib, arraysize(mib), path, &path_len, NULL, 0);
+  return rc ? "" : path;
 #else
 #error unknown OS
 #endif
