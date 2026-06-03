--- vendor/libbase/file.cpp	2024-08-29 19:46:57.000000000 +0200
+++ vendor/libbase/file.cpp	2026-03-21 14:02:01.670927000 +0100
@@ -35,6 +35,9 @@
 
 #if defined(__APPLE__)
 #include <mach-o/dyld.h>
+#endif
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
 #endif
 #if defined(_WIN32)
 #include <direct.h>
@@ -506,6 +509,12 @@
   if (result == 0 || result == sizeof(path) - 1) return "";
   path[PATH_MAX - 1] = 0;
   return path;
+#elif defined(__FreeBSD__)
+  int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+  char path[PATH_MAX + 1];
+  size_t path_len = sizeof(path);
+  if (sysctl(mib, 4, path, &path_len, nullptr, 0) < 0) return "";
+  return path;
 #elif defined(__EMSCRIPTEN__)
   abort();
 #else
