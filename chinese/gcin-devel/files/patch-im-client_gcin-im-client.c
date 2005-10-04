--- im-client/gcin-im-client.c.orig	Wed Oct  5 05:56:02 2005
+++ im-client/gcin-im-client.c	Wed Oct  5 05:56:23 2005
@@ -94,7 +94,7 @@
   get_gcin_im_srv_sock_path(sock_path, sizeof(sock_path));
   addr = sock_path;
   strcpy(serv_addr.sun_path, sock_path);
-  servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);
+  servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family) +1;
 
   if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
     perror("cannot open socket");
