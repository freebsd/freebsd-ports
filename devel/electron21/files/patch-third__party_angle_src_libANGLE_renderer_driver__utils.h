--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2022-06-17 14:20:10 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -183,7 +183,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
