We need to define PLATFORM_LINUX as the default if consumers don't do so.

--- Shared/All.h.orig	2025-02-07 08:39:49 UTC
+++ Shared/All.h
@@ -10,8 +10,8 @@ PLATFORM_ANDROID
 PLATFORM_ANDROID
 **************************************************************************************************/
 #if !defined(PLATFORM_WINDOWS) && !defined(PLATFORM_APPLE) && !defined(PLATFORM_LINUX) && !defined(PLATFORM_ANDROID)
-    #pragma message("No platform set for MACLib, defaulting to Windows")
-    #define PLATFORM_WINDOWS
+    #pragma message("No platform set for MACLib, defaulting to Linux")
+    #define PLATFORM_LINUX
 #endif
 
 #ifdef PLATFORM_ANDROID
