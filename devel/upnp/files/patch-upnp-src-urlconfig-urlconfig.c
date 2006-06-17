--- upnp/src/urlconfig/urlconfig.c.orig	Sat Jun 17 12:18:32 2006
+++ upnp/src/urlconfig/urlconfig.c	Sat Jun 17 12:21:52 2006
@@ -31,6 +31,7 @@
 
 #include "config.h"
 #include <assert.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
