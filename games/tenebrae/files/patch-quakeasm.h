--- quakeasm.h.orig	2020-09-30 11:25:10 UTC
+++ quakeasm.h
@@ -31,7 +31,7 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 
 #endif
 
-#ifdef __i386__
+#if defined(__i386__) && defined(USE_ASM)
 #define id386	1
 #else
 #define id386	0
