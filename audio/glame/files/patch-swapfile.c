--- src/swapfile/swapfile_fs.c.orig	Fri Dec  6 07:35:22 2002
+++ src/swapfile/swapfile_fs.c	Fri Dec  6 07:41:02 2002
@@ -44,6 +44,10 @@
 #define DEBUG 1
 #endif
 
+#if __FreeBSD__ >= 5
+#define __BSD_VISIBLE	1
+#endif
+
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <pthread.h>
