--- third_party/angle/src/common/system_utils_linux.cpp.orig	2024-02-21 00:22:07 UTC
+++ third_party/angle/src/common/system_utils_linux.cpp
@@ -15,8 +15,13 @@
 
 #include <array>
 
+#if ANGLE_PLATFORM_OPENBSD
+#include <pthread_np.h>
+#endif
+
 namespace angle
 {
+#if ANGLE_PLATFORM_LINUX
 std::string GetExecutablePath()
 {
     // We cannot use lstat to get the size of /proc/self/exe as it always returns 0
@@ -32,6 +37,7 @@ std::string GetExecutablePath()
     path[result] = '\0';
     return path;
 }
+#endif
 
 std::string GetExecutableDirectory()
 {
@@ -56,6 +62,10 @@ void SetCurrentThreadName(const char *name)
 {
     // There's a 15-character (16 including '\0') limit.  If the name is too big (and ERANGE is
     // returned), just ignore the name.
+#if ANGLE_PLATFORM_OPENBSD
+    pthread_set_name_np(pthread_self(), name);
+#else
     pthread_setname_np(pthread_self(), name);
+#endif
 }
 }  // namespace angle
