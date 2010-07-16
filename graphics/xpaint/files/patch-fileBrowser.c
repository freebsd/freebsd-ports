--- fileBrowser.c.orig	2010-04-28 17:02:11.000000000 +0900
+++ fileBrowser.c	2010-05-29 13:23:51.000000000 +0900
@@ -40,7 +40,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(SYSV) || defined(SVR4) || defined(__CYGWIN__) || defined(__VMS )
+#if defined(SYSV) || defined(SVR4) || defined(__CYGWIN__) || defined(__VMS ) || defined(__FreeBSD__)
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -513,7 +513,7 @@
 setCWD(arg_t * arg, char *dir)
 {
     DIR *dirp;
-#if defined(SYSV) || defined(SVR4) || defined(__alpha) || defined(__CYGWIN__)
+#if defined(SYSV) || defined(SVR4) || defined(__alpha) || defined(__CYGWIN__) || defined(__FreeBSD__)
     struct dirent *e;
 #else
     struct direct *e;
