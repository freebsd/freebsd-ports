--- src/swapfile/swapfile_fs.c.orig	2004-10-23 13:09:29 UTC
+++ src/swapfile/swapfile_fs.c
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
