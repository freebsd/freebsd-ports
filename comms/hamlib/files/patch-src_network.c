--- src/network.c.orig	2016-12-31 20:01:25 UTC
+++ src/network.c
@@ -48,6 +48,7 @@
 
 #ifdef HAVE_NETINET_IN_H
 #include <netinet/in.h>
+#include <netinet/tcp.h>
 #endif
 #if HAVE_NETDB_H
 #include <netdb.h>
@@ -117,6 +118,7 @@ int network_open(hamlib_port_t *rp, int 
 {
 	int fd;				/* File descriptor for the port */
 	int status;
+	int flag;
 	struct addrinfo hints, *res, *saved_res;
 	char *hoststr = NULL, *portstr = NULL, *bracketstr1, *bracketstr2;
 	char hostname[FILPATHLEN];
@@ -202,6 +204,10 @@ int network_open(hamlib_port_t *rp, int 
 					return -RIG_EIO;
 				}
 
+			/* Disable Nagle */
+			flag = 1;
+			setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &flag, sizeof(flag));
+
 			if ((status = connect(fd, res->ai_addr, res->ai_addrlen)) == 0)
 				{
 					break;
