--- udp.c.orig	Sat Jan  3 16:39:53 2004
+++ udp.c	Sat Jan  3 16:40:36 2004
@@ -74,7 +74,7 @@
 
     /* Read in the message */
     addr_len = sizeof(struct sockaddr_in);
-    len = recvfrom(isock, msg, sizeof(msg), 0,
+    len = recvfrom(isock, msg, maxsize, 0,
 		   (struct sockaddr *)&from_addr, &addr_len);
     if (len < 0) {
 	log_debug("recvfrom error %s", strerror(errno));
@@ -172,7 +172,7 @@
 		inet_ntoa(dns_srv[k].addr.sin_addr));
 	return (-1);
     }
-    else if (rc == len) {
+    else if (rc > len) {
 	log_msg(LOG_NOTICE, "packet too large: %s",
 		inet_ntoa(dns_srv[k].addr.sin_addr));
 	return (0);
@@ -202,7 +202,7 @@
     struct sockaddr_in from_addr;
     unsigned           addr_len;
 
-    len = dnsrecv(srvidx, msg, sizeof(msg));
+    len = dnsrecv(srvidx, msg, maxsize);
     if (opt_debug) {
 	char buf[80];
 	sprintf_cname(&msg[12], buf, 80);
