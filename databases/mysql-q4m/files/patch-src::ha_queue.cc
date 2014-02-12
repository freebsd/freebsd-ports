--- src/ha_queue.cc.orig	2014-02-06 14:51:01.000000000 +0900
+++ src/ha_queue.cc	2014-02-12 13:48:57.069544726 +0900
@@ -68,9 +68,7 @@
 #define Q4M_DELETE_MT_PWRITE 2
 #define Q4M_DELETE_SERIAL_PWRITE 3
 
-#if MYSQL_VERSION_ID < 50500
 #include "queue_config.h"
-#endif
 
 #if SIZEOF_OFF_T != 8
 #  error "support for 64-bit file offsets is mandatory"
@@ -763,7 +761,7 @@
     if (share->mmap_table(max(min((info->_header.end() + EXPAND_BY - 1)
 				  / EXPAND_BY * EXPAND_BY,
 				  mmap_max),
-			      EXPAND_BY))
+			      static_cast<ulonglong>EXPAND_BY))
 	!= 0) {
       log("mmap failed\n");
       goto ERR_AFTER_FILEOPEN;
