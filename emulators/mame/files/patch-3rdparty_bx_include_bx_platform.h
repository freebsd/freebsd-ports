--- 3rdparty/bx/include/bx/platform.h.orig	2015-04-29 06:18:54 UTC
+++ 3rdparty/bx/include/bx/platform.h
@@ -184,7 +184,7 @@
 #elif defined(__QNX__)
 #	undef  BX_PLATFORM_QNX
 #	define BX_PLATFORM_QNX 1
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #	undef  BX_PLATFORM_FREEBSD
 #	define BX_PLATFORM_FREEBSD 1
 #else
