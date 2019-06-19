--- src/v_src3.c.orig	2007-05-30 15:25:49 UTC
+++ src/v_src3.c
@@ -40,7 +40,7 @@
 #include <sys/stat.h>
 #endif
 
-#if defined(__CYGWIN32__) || defined(__SVR4) || defined(__hpux)
+#if defined(__CYGWIN32__) || defined(__SVR4) || defined(__hpux) || defined(__FreeBSD__)
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -51,7 +51,7 @@
 #endif
 
 /* REMOVEME - no longer supporting SunOS - maybe needed for hpux? */
-#if defined(__sparc) && !defined(__SVR4)  
+#if defined(__sparc) && !defined(__SVR4) && !defined(__FreeBSD__) 
 extern int32 tolower(int32);
 #endif
 
