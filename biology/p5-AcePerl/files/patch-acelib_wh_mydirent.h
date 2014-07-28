--- acelib/wh/mydirent.h.orig	Mon Jul 16 23:04:45 2001
+++ acelib/wh/mydirent.h	Mon Aug 13 12:41:59 2001
@@ -55,7 +55,7 @@
 extern char *getwd(char *pathname) ;
 #endif /* HP || SOLARIS || WIN32 */
 
-#if defined (POSIX) || defined(SUN) || defined(SUNSVR4) || defined(SOLARIS) || defined(DEC) || defined(ALPHA) || defined(SGI) || defined(LINUX) || defined(HP) || defined (INTEL_SOLARIS)
+#if defined (POSIX) || defined(SUN) || defined(SUNSVR4) || defined(SOLARIS) || defined(DEC) || defined(ALPHA) || defined(SGI) || defined(LINUX) || defined(HP) || defined (INTEL_SOLARIS) || defined (FREEBSD)
 #include <dirent.h>
   typedef struct dirent MYDIRENT ;
 #endif
