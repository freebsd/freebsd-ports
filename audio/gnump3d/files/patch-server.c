--- src/server.c.orig	Mon May 27 20:51:04 2002
+++ src/server.c	Mon May 27 20:51:22 2002
@@ -32,6 +32,7 @@
  */
 
 
+#include <sys/types.h>
 #include <arpa/inet.h>
 #include <ctype.h>
 #include <netinet/in.h>
