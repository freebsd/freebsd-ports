--- dnstable/query.c.orig	2014-05-21 21:37:25 UTC
+++ dnstable/query.c
@@ -15,6 +15,8 @@
  */
 
 #include <arpa/inet.h>
+#include <sys/socket.h>
+#include <sys/endian.h>
 
 #include "dnstable-private.h"
 
