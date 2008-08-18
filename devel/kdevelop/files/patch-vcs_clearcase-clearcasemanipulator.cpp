--- vcs/clearcase/clearcasemanipulator.cpp.orig	Tue Mar  4 17:09:11 2008
+++ vcs/clearcase/clearcasemanipulator.cpp	Tue Mar  4 17:09:35 2008
@@ -20,7 +20,7 @@
 #include <libgen.h>
 #include <errno.h>
 
-#if defined(Q_OS_MACX) || defined(MACOSX) || defined(Q_OS_SOLARIS)
+#if defined(Q_OS_MACX) || defined(MACOSX) || defined(Q_OS_SOLARIS) || defined(Q_OS_FREEBSD)
 //this function is taken from GNU libc
 //it does not exist on macos
 int getline(char **lineptr, size_t *n, FILE *stream)
