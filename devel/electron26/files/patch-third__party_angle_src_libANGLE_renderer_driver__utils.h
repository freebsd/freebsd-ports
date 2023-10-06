--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2023-08-10 01:51:11 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -218,7 +218,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
