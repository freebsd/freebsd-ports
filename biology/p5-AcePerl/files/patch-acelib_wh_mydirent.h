--- acelib/wh/mydirent.h.orig	2002-11-14 20:00:06 UTC
+++ acelib/wh/mydirent.h
@@ -55,7 +55,7 @@
 extern char *getwd(char *pathname) ;
 #endif /* HP || SOLARIS || WIN32 */
 
-#if defined (POSIX) || defined(SUN) || defined(SUNSVR4) || defined(SOLARIS) || defined(DEC) || defined(ALPHA) || defined(SGI) || defined(LINUX) || defined(HP) || defined (INTEL_SOLARIS)
+#if defined (POSIX) || defined(SUN) || defined(SUNSVR4) || defined(SOLARIS) || defined(DEC) || defined(ALPHA) || defined(SGI) || defined(LINUX) || defined(HP) || defined (INTEL_SOLARIS) || defined (FREEBSD)
 #include <dirent.h>
   typedef struct dirent MYDIRENT ;
 #endif
