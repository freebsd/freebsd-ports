--- im-srv/im-srv.c.orig	Mon Feb 14 10:18:04 2005
+++ im-srv/im-srv.c	Fri Mar 11 01:43:51 2005
@@ -121,7 +121,11 @@
   char sock_path[128];
   get_gcin_im_srv_sock_path(sock_path, sizeof(sock_path));
   strcpy(serv_addr.sun_path, sock_path);
+#ifdef	SUN_LEN
+  servlen = SUN_LEN (&serv_addr);
+#else
   servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);
+#endif
 
   dbg("-- %s\n",serv_addr.sun_path);
   struct stat st;
