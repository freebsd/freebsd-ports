--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2020-05-26 07:49:58 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -133,7 +133,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
