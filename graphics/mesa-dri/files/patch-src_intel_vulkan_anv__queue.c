- Define ETIME if missing
- Drop header that was never used

--- src/intel/vulkan/anv_queue.c.orig	2017-10-23 13:21:18 UTC
+++ src/intel/vulkan/anv_queue.c
@@ -26,8 +26,11 @@
  */
 
 #include <fcntl.h>
+#include <errno.h>
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 #include <unistd.h>
-#include <sys/eventfd.h>
 
 #include "anv_private.h"
 #include "vk_util.h"
