--- include/xmmintrin.h.orig	Wed Mar 17 14:42:12 2004
+++ include/xmmintrin.h	Wed Mar 17 14:42:31 2004
@@ -18,7 +18,7 @@
 #ifndef _INCLUDED_MM2
 #define _INCLUDED_MM2
 
-#if defined(__linux__) || defined(__QNX__)
+#if defined(__linux__) || defined(__QNX__) || defined(__FreeBSD__)
 #define __cdecl
 #endif
 
