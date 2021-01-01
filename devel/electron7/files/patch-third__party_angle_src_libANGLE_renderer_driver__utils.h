--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2019-12-12 12:42:33 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -114,7 +114,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
