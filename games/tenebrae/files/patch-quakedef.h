--- ./quakedef.h.orig	Sat Jun 10 12:08:13 2006
+++ ./quakedef.h	Sat Jun 10 12:08:13 2006
@@ -74,11 +74,6 @@
 
 #endif
 
-//PENTA: win32 we use assembler
-#if defined(_WIN32) || defined __glx__
-#define USE_ASM 1
-#endif
-
 #if defined(__i386__) && defined(USE_ASM)
 #define id386	1
 #else
