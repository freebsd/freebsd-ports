--- ./src/modules/cicero.c.orig	2012-07-11 11:05:05.000000000 +0200
+++ ./src/modules/cicero.c	2013-11-15 08:51:41.687674164 +0100
@@ -32,6 +32,7 @@
 #include <langinfo.h>
 #include <sys/stat.h>
 #include <semaphore.h>
+#include <spd_utils.h>
 
 #include "module_utils.h"
 
@@ -377,9 +378,7 @@
 						break;
 					}
 					if (ret > 0)
-						TEMP_FAILURE_RETRY(read
-								   (fd1[0], b,
-								    2));
+						safe_read(fd1[0], b, 2);
 					if (cicero_stop) {
 						cicero_speaking = 0;
 						module_report_event_stop();
