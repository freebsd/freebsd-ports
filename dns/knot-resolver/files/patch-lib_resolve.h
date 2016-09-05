--- lib/resolve.h.orig	2016-08-24 12:05:47 UTC
+++ lib/resolve.h
@@ -18,6 +18,7 @@
 
 #include <netinet/in.h>
 #include <libknot/packet/pkt.h>
+#include <sys/socket.h>
 
 #include "lib/cookies/control.h"
 #include "lib/cookies/lru_cache.h"
