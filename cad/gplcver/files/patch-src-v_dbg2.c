--- src/v_dbg2.c.orig	Fri Jan 20 09:54:37 2006
+++ src/v_dbg2.c	Fri Jan 20 09:54:58 2006
@@ -44,7 +44,7 @@
 #endif
 
 /* REMOVEME - no longer supporting SunOS - maybe needed for hpux? */
-#if defined(__sparc) && !defined(__SVR4)  
+#if defined(__sparc) && !defined(__SVR4) && !defined(__FreeBSD__) 
 extern int32 tolower(int32);
 extern int32 sscanf(char *, char *, ...); 
 #endif
