--- net.h.orig	Wed Mar 21 11:32:05 2007
+++ net.h	Wed Mar 21 11:33:28 2007
@@ -218,6 +218,6 @@
 int udp_connect(int local_port,char *remote_host,int remote_port);
 
 /* Listen on the specified port */
-int ip_listen(int port,int sock_type,int max_fd,int fd_array[]);
+int ip_listen(char *ip_address,int port,int sock_type,int max_fd,int fd_array[]);
 
 #endif
