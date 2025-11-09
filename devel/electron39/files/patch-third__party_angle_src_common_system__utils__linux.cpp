--- third_party/angle/src/common/system_utils_linux.cpp.orig	2025-10-21 20:19:54 UTC
+++ third_party/angle/src/common/system_utils_linux.cpp
@@ -19,10 +19,15 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#if ANGLE_PLATFORM_OPENBSD
+#include <pthread_np.h>
+#endif
+
 #include <array>
 
 namespace angle
 {
+#if ANGLE_PLATFORM_LINUX
 std::string GetExecutablePath()
 {
     // We cannot use lstat to get the size of /proc/self/exe as it always returns 0
@@ -38,6 +43,7 @@ std::string GetExecutablePath()
     path[result] = '\0';
     return path;
 }
+#endif
 
 std::string GetExecutableDirectory()
 {
@@ -63,6 +69,10 @@ void SetCurrentThreadName(const char *name)
     // There's a 15-character (16 including '\0') limit.  If the name is too big (and ERANGE is
     // returned), name will be ignored.
     ASSERT(strlen(name) < 16);
+#if ANGLE_PLATFORM_OPENBSD
+    pthread_set_name_np(pthread_self(), name);
+#else
     pthread_setname_np(pthread_self(), name);
+#endif
 }
 }  // namespace angle
