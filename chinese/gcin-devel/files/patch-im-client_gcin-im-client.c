--- im-client/gcin-im-client.c~	Thu Oct 13 01:11:53 2005
+++ im-client/gcin-im-client.c	Thu Oct 13 01:14:23 2005
@@ -94,7 +94,11 @@
   get_gcin_im_srv_sock_path(sock_path, sizeof(sock_path));
   addr = sock_path;
   strcpy(serv_addr.sun_path, sock_path);
+#ifdef SUN_LEN
+  servlen = SUN_LEN(&serv_addr);
+#else
   servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);
+#endif
 
   if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
     perror("cannot open socket");
