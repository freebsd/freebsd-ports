--- include/xmmintrin.h.orig	Wed Mar 17 14:42:12 2004
+++ include/xmmintrin.h	Wed Mar 17 14:42:31 2004
@@ -18,7 +18,7 @@
 #ifndef _INCLUDED_MM2
 #define _INCLUDED_MM2
 
-#if defined (__linux__) || defined (__QNX__)    /* EIA Compiler does not compile either */
+#if defined (__linux__) || defined (__FreeBSD__) || defined(__QNX__)   /* EIA Compiler does not compile either */
 #define __cdecl
 #endif
 
