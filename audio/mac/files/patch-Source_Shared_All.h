We need to define PLATFORM_LINUX as the default if consumers don't do so.

Fix runtime for little endian archs. At least on amd64, _BIG_ENDIAN is defined
somewhere in the toolchain, causing the byte order to be reversed.

--- Source/Shared/All.h.orig	2026-07-01 07:25:49 UTC
+++ Source/Shared/All.h
@@ -19,7 +19,7 @@ PLATFORM_ANDROID
 #if !defined(PLATFORM_WINDOWS) && !defined(PLATFORM_APPLE) && !defined(PLATFORM_LINUX) && !defined(PLATFORM_ANDROID)
     #if defined(__ANDROID__)
         #define PLATFORM_ANDROID
-    #elif defined(__linux__)
+    #elif defined(__linux__) || defined(__FreeBSD__)
         #define PLATFORM_LINUX
     #elif defined(__APPLE__)
         #define PLATFORM_APPLE
@@ -364,7 +364,7 @@ Byte order
 #define APE_LITTLE_ENDIAN     1234
 #define APE_BIG_ENDIAN        4321
 
-#if defined(_BIG_ENDIAN) || defined(__BIG_ENDIAN__) || (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__))
+#if defined(__BIG_ENDIAN__) || (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__))
 #define APE_BYTE_ORDER        APE_BIG_ENDIAN
 #else
 #define APE_BYTE_ORDER        APE_LITTLE_ENDIAN
