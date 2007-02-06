--- bhm.cpp.orig	Tue Feb  6 16:04:04 2007
+++ bhm.cpp	Tue Feb  6 16:05:12 2007
@@ -13,7 +13,9 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
+#ifndef __FreeBSD__
 #include <netinet/ip.h>
+#endif
 
 #include "postal.h"
 #include "logit.h"
