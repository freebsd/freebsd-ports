--- src/v_ex2.c.orig	Fri Jan 20 09:48:49 2006
+++ src/v_ex2.c	Fri Jan 20 09:49:23 2006
@@ -38,7 +38,7 @@
 #endif
 
 /* REMOVEME - no longer supporting SunOS - maybe needed for hpux? */
-#if defined(__sparc) && !defined(__SVR4)  
+#if defined(__sparc) && !defined(__SVR4) && !defined(__FreeBSD__) 
 extern int32 tolower(int32);
 extern ungetc(int32 c, FILE *);
 #endif
