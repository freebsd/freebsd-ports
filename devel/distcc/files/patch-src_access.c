
$FreeBSD$

--- src/access.c.orig	Sun Mar  2 16:59:12 2003
+++ src/access.c	Sun Mar  2 16:59:29 2003
@@ -30,6 +30,7 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
