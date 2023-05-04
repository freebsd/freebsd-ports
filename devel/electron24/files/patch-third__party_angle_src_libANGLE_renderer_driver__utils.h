--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2023-03-30 00:40:32 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -206,7 +206,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
