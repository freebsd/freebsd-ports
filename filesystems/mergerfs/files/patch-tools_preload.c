--- tools/preload.c.orig	2024-02-29 20:41:22 UTC
+++ tools/preload.c
@@ -25,10 +25,25 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <stdarg.h>
-#include <sys/stat.h>
+#include <sys/stat.h>
+#ifdef __linux__
+#define S_IFMT S_IFMT
+#define S_IFREG S_IFREG
+#else
+#define S_IFMT 0
+#define S_IFREG 0
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 #include <fcntl.h>
+
+#ifdef __linux__
+#define O_TMPFILE O_TMPFILE
+#define O_PATH O_PATH
+#else
+#define O_TMPFILE 0
+#define O_PATH 0
+#endif
 
 typedef char IOCTL_BUF[4096];
 #define IOCTL_APP_TYPE  0xDF
