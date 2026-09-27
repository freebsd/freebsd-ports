-- Adapt pdfium's test path helper to FreeBSD: use sys/syslimits.h instead of
-- linux/limits.h and struct stat/stat() instead of the Linux-only stat64.
--- testing/utils/path_service.cpp.orig	2026-09-24 10:57:02 UTC
+++ testing/utils/path_service.cpp
@@ -12,8 +12,8 @@
 #include <mach-o/dyld.h>
 #include <sys/stat.h>
 #else  // Linux
-#include <linux/limits.h>
 #include <sys/stat.h>
+#include <sys/syslimits.h>
 #include <unistd.h>
 #endif  // _WIN32
 
@@ -25,6 +25,12 @@ namespace {
 namespace {
 
 #if defined(__APPLE__) || (defined(ANDROID) && __ANDROID_API__ < 21)
+using stat_wrapper_t = struct stat;
+
+int CallStat(const char* path, stat_wrapper_t* sb) {
+  return stat(path, sb);
+}
+#elif defined(__FreeBSD__)
 using stat_wrapper_t = struct stat;
 
 int CallStat(const char* path, stat_wrapper_t* sb) {
