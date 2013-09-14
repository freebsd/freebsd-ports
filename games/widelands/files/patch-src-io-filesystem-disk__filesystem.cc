--- src/io/filesystem/disk_filesystem.cc.orig	2012-04-23 13:46:49.000000000 +0400
+++ src/io/filesystem/disk_filesystem.cc	2013-09-13 20:35:42.666227898 +0400
@@ -43,6 +43,7 @@
 #include <sys/statvfs.h>
 #include <sys/types.h>
 #include <fcntl.h>
+#include <unistd.h> // for unlink()
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE // for O_NOATIME
 #endif
