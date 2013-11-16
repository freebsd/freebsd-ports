--- ./src/server/speaking.c.orig	2012-07-11 11:05:06.000000000 +0200
+++ ./src/server/speaking.c	2013-11-15 11:20:31.405951238 +0100
@@ -39,6 +39,7 @@
 #include "output.h"
 #include "speaking.h"
 #include "sem_functions.h"
+#include <spd_utils.h>
 
 TSpeechDMessage *current_message = NULL;
 static SPDPriority highest_priority = 0;
@@ -87,10 +88,7 @@
 				char buf[1];
 				MSG(5,
 				    "wait_for_poll: activity in Speech Dispatcher");
-				const ssize_t rd_bytes =
-				    TEMP_FAILURE_RETRY(read
-						       (poll_fds[0].fd, buf,
-							1));
+				const ssize_t rd_bytes = safe_read(poll_fds[0].fd, buf, 1);
 				if (rd_bytes != 1)
 					FATAL
 					    ("read from polled fd: could not read 1 byte");
