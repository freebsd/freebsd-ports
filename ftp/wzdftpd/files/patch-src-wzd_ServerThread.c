--- src/wzd_ServerThread.c.orig	Sat Aug 28 19:48:52 2004
+++ src/wzd_ServerThread.c	Sat Aug 28 19:49:22 2004
@@ -28,6 +28,7 @@
 #include <winsock2.h>
 #else
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -40,7 +41,6 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h> /* isspace */
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h>
 #include <errno.h>
