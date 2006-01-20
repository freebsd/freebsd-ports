--- src/v_ms.c.orig	Fri Jan 20 09:56:30 2006
+++ src/v_ms.c	Fri Jan 20 09:56:48 2006
@@ -50,7 +50,7 @@
 #endif
 
 /* REMOVEME - no longer supporting SunOS - maybe needed for hpux? */
-#if defined(__sparc) && !defined(__SVR4)  
+#if defined(__sparc) && !defined(__SVR4) && !defined(__FreeBSD__) 
 extern int32 tolower(int32);
 extern ungetc(int32 c, FILE *);
 extern long time (long *);
