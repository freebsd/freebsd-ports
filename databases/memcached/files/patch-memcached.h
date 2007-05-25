--- ./memcached.h.orig	Fri May 25 14:34:08 2007
+++ ./memcached.h	Fri May 25 14:34:47 2007
@@ -3,6 +3,7 @@
 
 #include "config.h"
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/time.h>
 #include <netinet/in.h>
 #include <event.h>
