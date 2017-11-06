--- src/libzbxpgsql.c.orig	2016-06-25 14:18:03 UTC
+++ src/libzbxpgsql.c
@@ -24,6 +24,9 @@
  */
 
 #include "libzbxpgsql.h"
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 // Define custom keys
 static ZBX_METRIC keys[] =
