
$FreeBSD$

--- server/aux.c	2001/04/12 12:54:48	1.1
+++ server/aux.c	2001/04/12 12:55:13
@@ -28,6 +28,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
