--- mysqlshdk/libs/utils/utils_general.cc.orig	2026-01-26 17:04:27 UTC
+++ mysqlshdk/libs/utils/utils_general.cc
@@ -35,6 +35,10 @@
 #include "include/mysh_config.h"
 #include "my_config.h"
 
+#ifdef __FreeBSD__
+#include <sys/wait.h>
+#endif
+
 #ifdef WIN32
 #include <Lmcons.h>
 #else
@@ -240,7 +244,7 @@ std::string errno_to_string(int err) {
 #define strerror_r(E, B, S) strerror_s(B, S, E)
 #endif
 
-#if defined(_WIN32) || defined(__sun) || defined(__APPLE__) || \
+#if defined(__FreeBSD__) || defined(_WIN32) || defined(__sun) || defined(__APPLE__) || \
     ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) &&   \
      !_GNU_SOURCE)  // NOLINT
   char buf[256];
@@ -1025,6 +1029,8 @@ OperatingSystem get_os_type() {
   os = OperatingSystem::MACOS;
 #elif __sun
   os = OperatingSystem::SOLARIS;
+#elif __FreeBSD__
+  os = OperatingSystem::FREEBSD;
 #elif __linux__
   os = OperatingSystem::LINUX;
 
