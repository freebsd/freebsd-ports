
$FreeBSD$

--- src/soup-core/soup-private.h	2001/05/28 12:03:44	1.1
+++ src/soup-core/soup-private.h	2001/05/28 12:05:03
@@ -16,7 +16,10 @@
 #ifndef SOAP_PRIVATE_H
 #define SOAP_PRIVATE_H 1
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 
 #include "soup-context.h"
 #include "soup-server.h"
