--- mysqlshdk/libs/utils/utils_file.cc.orig	2026-02-13 15:35:16 UTC
+++ mysqlshdk/libs/utils/utils_file.cc
@@ -64,7 +64,7 @@
 #include <limits.h>
 #include <mach-o/dyld.h>
 #else
-#ifdef __sun
+#if defined(__sun) || defined(__FreeBSD__)
 #include <limits.h>
 #else
 #include <linux/limits.h>
@@ -72,6 +72,10 @@
 #endif
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
+
 namespace shcore {
 namespace {
 #ifdef _WIN32
@@ -247,10 +251,19 @@ std::string get_binary_path() {
     throw std::runtime_error(
         str_format("get_binary_folder: Readlink failed with error %d", errno));
   }
+#else
+#ifdef __FreeBSD__
+  char path[PATH_MAX]{'\0'};
+  size_t size = sizeof(path);
+  int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+  if (sysctl(mib, 4, path, &size, NULL, 0) == 0) {
+    exe_path.assign(path);
+  }
 #endif
 #endif
 #endif
 #endif
+#endif
 
   return exe_path;
 }
@@ -408,7 +421,7 @@ size_t file_size(const char *path) {
 #if defined(_WIN32)
   struct _stat64 file_stat = {};
   const auto ret = _wstat64(utf8_to_wide(path).c_str(), &file_stat);
-#elif defined(__APPLE__) || defined(__SUNPRO_CC)
+#elif defined(__APPLE__) || defined(__SUNPRO_CC) || defined(__FreeBSD__)
   struct stat file_stat = {};
   const auto ret = ::stat(path, &file_stat);
 #else
