--- modules/zeroconf/libwzd_avahi.h.orig	Wed May 31 14:55:16 2006
+++ modules/zeroconf/libwzd_avahi.h	Wed May 31 14:56:17 2006
@@ -29,6 +29,7 @@
 #include <stdlib.h>
 #include <assert.h>
 #include <string.h>
+#include <pthread.h>
 
 #include <libwzd-core/wzd_structs.h>
 #include <libwzd-core/wzd_log.h>
