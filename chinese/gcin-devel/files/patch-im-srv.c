--- im-srv/im-srv.c.orig	Mon Feb 14 10:18:04 2005
+++ im-srv/im-srv.c	Wed Mar  2 02:49:58 2005
@@ -121,7 +121,7 @@
   char sock_path[128];
   get_gcin_im_srv_sock_path(sock_path, sizeof(sock_path));
   strcpy(serv_addr.sun_path, sock_path);
-  servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);
+  servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family) + 1;
 
   dbg("-- %s\n",serv_addr.sun_path);
   struct stat st;
