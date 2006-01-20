--- src/v_src3.c.orig	Fri Jan 20 09:40:09 2006
+++ src/v_src3.c	Fri Jan 20 09:41:23 2006
@@ -49,7 +49,7 @@
 #endif
 
 /* REMOVEME - no longer supporting SunOS - maybe needed for hpux? */
-#if defined(__sparc) && !defined(__SVR4)  
+#if defined(__sparc) && !defined(__SVR4) && !defined(__FreeBSD__) 
 extern int32 tolower(int32);
 #endif
 
