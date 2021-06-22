--- tools/bam-loader/loader-imp.c.orig	2021-06-20 16:59:47 UTC
+++ tools/bam-loader/loader-imp.c
@@ -71,6 +71,7 @@
 #include <sysalloc.h>
 #include <atomic32.h>
 
+#include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/mman.h>
