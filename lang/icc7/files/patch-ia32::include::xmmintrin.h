--- ia32/include/xmmintrin.h.orig	Fri Jan 10 18:47:00 2003
+++ ia32/include/xmmintrin.h	Fri Jan 10 18:50:35 2003
@@ -18,7 +18,7 @@
 #ifndef _INCLUDED_MM2
 #define _INCLUDED_MM2
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define __cdecl
 #endif
 
