--- src/cddb.c.orig	Wed Jan  1 22:29:03 2003
+++ src/cddb.c	Wed Jan  1 22:29:17 2003
@@ -29,6 +29,7 @@
 #include <sys/socket.h>
 #include <netdb.h>
 #include <errno.h>
+#include <netinet/in.h>
 
 #include "cddb.h"
 #include "easytag.h"
