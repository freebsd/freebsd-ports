--- upnp/src/urlconfig/urlconfig.c.orig	Sun Apr  6 02:29:45 2003
+++ upnp/src/urlconfig/urlconfig.c	Sun Apr  6 02:30:02 2003
@@ -30,6 +30,7 @@
 ///////////////////////////////////////////////////////////////////////////
 
 #include <assert.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
