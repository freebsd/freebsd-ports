--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2019-04-08 08:20:00 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -107,7 +107,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
