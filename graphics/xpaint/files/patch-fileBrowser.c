Suppport dirent(3) if defined.

--- fileBrowser.c.orig	2020-09-02 07:24:21 UTC
+++ fileBrowser.c
@@ -48,7 +48,7 @@ extern Xaw3dXftData *xaw3dxft_data;
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(SYSV) || defined(SVR4) || defined(__CYGWIN__) || defined(__VMS )
+#if HAVE_DIRENT_H
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -563,7 +563,7 @@ setCWD(arg_t * arg, char *dir)
 setCWD(arg_t * arg, char *dir)
 {
     DIR *dirp;
-#if defined(SYSV) || defined(SVR4) || defined(__alpha) || defined(__CYGWIN__)
+#if HAVE_DIRENT_H
     struct dirent *e;
 #else
     struct direct *e;
