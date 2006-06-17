--- ./quakeasm.h.orig	Sat Jun 10 12:08:13 2006
+++ ./quakeasm.h	Sat Jun 10 12:08:13 2006
@@ -31,7 +31,7 @@
 
 #endif
 
-#ifdef __i386__
+#if defined(__i386__) && defined(USE_ASM)
 #define id386	1
 #else
 #define id386	0
