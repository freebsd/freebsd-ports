- Define ETIME if missing

--- src/intel/vulkan/anv_gem.c.orig	2017-10-23 13:21:18 UTC
+++ src/intel/vulkan/anv_gem.c
@@ -26,6 +26,9 @@
 #include <sys/mman.h>
 #include <string.h>
 #include <errno.h>
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 #include <unistd.h>
 #include <fcntl.h>
 
