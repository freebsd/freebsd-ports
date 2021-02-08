--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2021-01-07 00:39:27 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -145,7 +145,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
