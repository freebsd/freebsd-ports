--- src/ha_queue.cc.orig	2013-05-21 18:33:11.000000000 +0900
+++ src/ha_queue.cc	2014-01-22 18:50:08.633290803 +0900
@@ -64,9 +64,7 @@
 #define Q4M_DELETE_MT_PWRITE 2
 #define Q4M_DELETE_SERIAL_PWRITE 3
 
-#if MYSQL_VERSION_ID < 50500
 #include "queue_config.h"
-#endif
 
 #if SIZEOF_OFF_T != 8
 #  error "support for 64-bit file offsets is mandatory"
