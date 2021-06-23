--- lib/repository_admin.c.orig	2021-06-23 15:24:57 UTC
+++ lib/repository_admin.c
@@ -22,6 +22,7 @@
 #include <sys/wait.h>
 
 #include <dirent.h>
+#include <endian.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <stdint.h>
