--- fileBrowser.c.orig	2014-05-08 13:50:48 UTC
+++ fileBrowser.c
@@ -47,7 +47,7 @@ extern Xaw3dXftData *xaw3dxft_data;
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(SYSV) || defined(SVR4) || defined(__CYGWIN__) || defined(__VMS )
+#if defined(SYSV) || defined(SVR4) || defined(__CYGWIN__) || defined(__VMS ) || defined(BSD)
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -562,7 +562,7 @@ static void 
 setCWD(arg_t * arg, char *dir)
 {
     DIR *dirp;
-#if defined(SYSV) || defined(SVR4) || defined(__alpha) || defined(__CYGWIN__)
+#if defined(SYSV) || defined(SVR4) || defined(__alpha) || defined(__CYGWIN__) || defined(BSD)
     struct dirent *e;
 #else
     struct direct *e;
