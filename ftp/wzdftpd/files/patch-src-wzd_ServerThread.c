--- src/wzd_ServerThread.c.orig	Thu Apr 15 10:27:07 2004
+++ src/wzd_ServerThread.c	Tue Apr 20 10:52:06 2004
@@ -28,6 +28,7 @@
 #include <winsock2.h>
 #else
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -39,7 +40,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h>
 #include <errno.h>
