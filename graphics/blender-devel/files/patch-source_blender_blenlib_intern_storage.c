--- source/blender/blenlib/intern/storage.c.orig	Fri Jul  7 14:15:04 2006
+++ source/blender/blenlib/intern/storage.c	Fri Jul  7 14:17:47 2006
@@ -50,7 +50,7 @@
 #include <time.h>
 #include <sys/stat.h>
 
-#if !defined(linux) && (defined(__sgi) || defined(__sun__) || defined(__sun) || defined(__sparc) || defined(__sparc__))
+#if !defined(__FreeBSD__) && !defined(linux) && (defined(__sgi) || defined(__sun__) || defined(__sun) || defined(__sparc) || defined(__sparc__))
 #include <sys/statfs.h>
 #endif
 
@@ -194,7 +194,7 @@
 #ifdef __BeOS
 	return -1;
 #endif
-#if !defined(linux) && (defined (__sgi) || defined (__sun__) || defined (__sun) || defined(__sparc) || defined(__sparc__))
+#if !defined(__FreeBSD__) && !defined(linux) && (defined (__sgi) || defined (__sun__) || defined (__sun) || defined(__sparc) || defined(__sparc__))
 
 	if (statfs(name, &disk, sizeof(struct statfs), 0)){
 		/* printf("diskfree: Couldn't get information about %s.\n",dir); */
