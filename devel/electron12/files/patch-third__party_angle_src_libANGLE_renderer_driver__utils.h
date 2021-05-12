--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2021-04-14 01:15:19 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -151,7 +151,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
