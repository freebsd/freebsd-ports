--- mono/mini/mini-x86.h.orig	2008-12-11 21:27:14.000000000 -0300
+++ mono/mini/mini-x86.h	2008-12-11 21:27:35.000000000 -0300
@@ -43,7 +43,7 @@
 
 #endif /* PLATFORM_WIN32 */
 
-#if defined( __linux__) || defined(__sun) || defined(__APPLE__) || defined(__NetBSD__)
+#if defined( __linux__) || defined(__sun) || defined(__APPLE__) || defined(__NetBSD__) || defined(__FreeBSD__)
 #define MONO_ARCH_USE_SIGACTION
 #endif
 
