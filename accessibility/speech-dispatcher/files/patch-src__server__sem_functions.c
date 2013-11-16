--- ./src/server/sem_functions.c.orig	2012-07-11 11:05:06.000000000 +0200
+++ ./src/server/sem_functions.c	2013-11-15 11:19:15.965146025 +0100
@@ -28,13 +28,13 @@
 
 #include "speechd.h"
 #include "sem_functions.h"
+#include <spd_utils.h>
 
 void speaking_semaphore_post(void)
 {
 	char buf[1];
 	buf[0] = 42;
-	const ssize_t wr_bytes =
-	    TEMP_FAILURE_RETRY(write(speaking_pipe[1], buf, 1));
+	const ssize_t wr_bytes = safe_write(speaking_pipe[1], buf, 1);
 	if (wr_bytes != 1)
 		FATAL("write to polled fd: could not write 1 byte");
 }
