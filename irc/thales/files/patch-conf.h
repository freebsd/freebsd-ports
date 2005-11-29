--- src/conf.h	Sun Jan 11 00:26:12 2004
+++ src/conf.h	Sat Apr  2 10:42:03 2005
@@ -23,7 +23,7 @@
 #include "log.h"
 
 /* Configuration directives. */
-#define THALES_CONF "thales.conf"
+#define THALES_CONF "%%PREFIX%%/etc/thales.conf"
 #define MAXPARAMS	4
 
 typedef struct
