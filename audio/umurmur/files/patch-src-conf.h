--- src/conf.h.old	2011-12-04 19:11:49.751119971 +0200
+++ src/conf.h	2011-12-04 19:13:32.677786798 +0200
@@ -33,7 +33,7 @@
 
 #include "messages.h"
 
-#define DEFAULT_CONFIG "/etc/umurmur.conf"
+#define DEFAULT_CONFIG "%%PREFIX%%/etc/umurmur/umurmur.conf"
 
 typedef enum param {
 	CERTIFICATE,
