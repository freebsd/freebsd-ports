--- src/swapfile/swapfile_fs.c.orig	Sat Oct 23 22:09:29 2004
+++ src/swapfile/swapfile_fs.c	Tue Mar 29 23:11:17 2005
@@ -44,8 +44,12 @@
 #define DEBUG 1
 #endif
 
-#include <sys/stat.h>
+#if __FreeBSD__ >= 5
+#define __BSD_VISIBLE	1
+#endif
+
 #include <sys/types.h>
+#include <sys/stat.h>
 #include <pthread.h>
 #include <fcntl.h>
 #include <dirent.h>
