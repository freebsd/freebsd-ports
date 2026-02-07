--- audio/drivers/alsathread.c.orig	2025-11-20 00:17:08 UTC
+++ audio/drivers/alsathread.c
@@ -24,7 +24,7 @@
 #include <rthreads/rthreads.h>
 #include <queues/fifo_queue.h>
 #include <string/stdstring.h>
-#include <asm-generic/errno.h>
+#include <errno.h>
 
 #include "../audio_driver.h"
 #include "../common/alsa.h" /* For some common functions/types */
