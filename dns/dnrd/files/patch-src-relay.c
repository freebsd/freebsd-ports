--- src/relay.c.orig	Mon Jul 19 13:17:21 2004
+++ src/relay.c	Wed Jul 28 22:27:44 2004
@@ -19,12 +19,12 @@
  */
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <errno.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <unistd.h>
 #include <string.h>
 
