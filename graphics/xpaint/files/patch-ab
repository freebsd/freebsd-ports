--- fileName.c.orig	Mon Nov  8 21:41:46 2004
+++ fileName.c	Sun Jan 30 18:55:53 2005
@@ -38,7 +38,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(SYSV) || defined(SVR4) || defined(__CYGWIN__) || defined(__VMS )
+#if defined(SYSV) || defined(SVR4) || defined(__CYGWIN__) || defined(__VMS ) || defined(__FreeBSD__)
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -409,7 +409,7 @@
 setCWD(arg_t * arg, char *dir)
 {
     DIR *dirp;
-#if defined(SYSV) || defined(SVR4) || defined(__alpha) || defined(__CYGWIN__)
+#if defined(SYSV) || defined(SVR4) || defined(__alpha) || defined(__CYGWIN__) || defined(__FreeBSD__)
     struct dirent *e;
 #else
     struct direct *e;
