--- base/file.cpp.orig	2016-09-28 18:07:09 UTC
+++ base/file.cpp
@@ -18,6 +18,9 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <limits.h> // PATH_MAX
+#include <stdio.h> // BUFSIZ
+#include <string.h> // strerror
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -34,6 +37,9 @@
 #if defined(__APPLE__)
 #include <mach-o/dyld.h>
 #endif
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
 #if defined(_WIN32)
 #include <windows.h>
 #endif
@@ -231,6 +237,17 @@ std::string GetExecutablePath() {
   if (result == 0 || result == sizeof(path) - 1) return "";
   path[PATH_MAX - 1] = 0;
   return path;
+#elif defined(KERN_PROC_PATHNAME)
+  char path[PATH_MAX + 1];
+  size_t path_len = sizeof(path);
+  int mib[] = {
+    CTL_KERN,
+    KERN_PROC,
+    KERN_PROC_PATHNAME,
+    getpid()
+  };
+  int rc = sysctl(mib, arraysize(mib), path, &path_len, NULL, 0);
+  return rc ? "" : path;
 #else
 #error unknown OS
 #endif
