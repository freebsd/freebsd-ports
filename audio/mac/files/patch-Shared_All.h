We need to define PLATFORM_LINUX as the default if consumers don't do so.

Fix runtime for little endian archs. At least on amd64, _BIG_ENDIAN is defined
somewhere in the toolchain, causing the byte order to be reversed.

--- Shared/All.h.orig	2025-10-15 08:20:58 UTC
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
@@ -311,7 +311,7 @@ Byte order
 #define APE_LITTLE_ENDIAN     1234
 #define APE_BIG_ENDIAN        4321
 
-#if defined(_BIG_ENDIAN) || defined(__BIG_ENDIAN__) || (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__))
+#if defined(__BIG_ENDIAN__) || (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__))
 #define APE_BYTE_ORDER        APE_BIG_ENDIAN
 #else
 #define APE_BYTE_ORDER        APE_LITTLE_ENDIAN
