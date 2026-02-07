--- src/bin/animate/glob.c.orig	2014-03-12 16:51:10 UTC
+++ src/bin/animate/glob.c
@@ -41,7 +41,9 @@ static char sccsid[] = "@(#)glob.c	5.7 (
 #include <errno.h>
 #include <pwd.h>
 
-#if !defined(dirfd) && !defined(__GLIBC__) && !defined(__linux__) && !defined(__FreeBSD__) && !defined(__CYGWIN__) && !defined(__APPLE__)
+#if !defined(dirfd) && !defined(__GLIBC__) && !defined(__linux__) && \
+    !defined(__FreeBSD__) && !defined(__CYGWIN__) && !defined(__APPLE__) && \
+    !defined(__DragonFly__)
 #define dirfd(dirp)  ((dirp)->dd_fd)
 #endif
 
