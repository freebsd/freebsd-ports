--- third_party/angle/src/libANGLE/renderer/driver_utils.cpp.orig	2021-07-15 19:15:42 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.cpp
@@ -17,7 +17,7 @@
 #    include <sys/system_properties.h>
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 #    include <sys/utsname.h>
 #endif
 
@@ -230,7 +230,7 @@ OSVersion GetMacOSVersion()
 }
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 bool ParseLinuxOSVersion(const char *version, int *major, int *minor, int *patch)
 {
     errno = 0;  // reset global error flag.
@@ -242,6 +242,14 @@ bool ParseLinuxOSVersion(const char *version, int *maj
     }
 
     *minor = static_cast<int>(strtol(next + 1, &next, 10));
+#if defined(__FreeBSD__)
+    if (next == nullptr || *next != '-' || errno != 0)
+    {
+        return false;
+    }
+
+    *patch = 0;
+#else
     if (next == nullptr || *next != '.' || errno != 0)
     {
         return false;
@@ -252,6 +260,7 @@ bool ParseLinuxOSVersion(const char *version, int *maj
     {
         return false;
     }
+#endif
 
     return true;
 }
@@ -259,7 +268,7 @@ bool ParseLinuxOSVersion(const char *version, int *maj
 
 OSVersion GetLinuxOSVersion()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     struct utsname uname_info;
     if (uname(&uname_info) != 0)
     {
