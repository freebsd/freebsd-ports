--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2022-05-11 07:17:23 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -173,7 +173,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
