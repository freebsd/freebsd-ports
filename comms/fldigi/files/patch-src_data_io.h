--- src/include/data_io.h.orig	2014-11-27 01:39:00.000000000 -0800
+++ src/include/data_io.h	2014-11-27 01:39:29.000000000 -0800
@@ -27,6 +27,8 @@
 #ifndef fldigi_data_io_h
 #define fldigi_data_io_h
 
+#include <sys/types.h>	// For time_t
+
 #define DEFAULT_ARQ_IP_ADDRESS    "127.0.0.1"
 #define DEFAULT_ARQ_IP_PORT       "7322"
 
