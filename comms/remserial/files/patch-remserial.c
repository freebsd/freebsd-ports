--- ./remserial.c.orig	2011-01-05 10:31:12.000000000 +0100
+++ ./remserial.c	2011-01-05 10:31:12.000000000 +0100
@@ -34,6 +34,8 @@
 #include <netinet/in.h>
 #include <netdb.h>
 
+#include "define.h"
+
 struct sockaddr_in addr,remoteaddr;
 int sockfd = -1;
 int port = 23000;
@@ -417,7 +419,7 @@
 }
 
 void usage(char *progname) {
-	printf("Remserial version 1.3.  Usage:\n");
+	printf("Remserial version %s.  Usage:\n", VERSION);
 	printf("remserial [-r machinename] [-p netport] [-s \"stty params\"] [-m maxconnect] device\n\n");
 
 	printf("-r machinename		The remote machine name to connect to.  If not\n");
