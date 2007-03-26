--- hypervisor.h.orig	Wed Mar 21 10:58:06 2007
+++ hypervisor.h	Wed Mar 21 11:09:40 2007
@@ -136,6 +136,6 @@
 int hypervisor_stopsig(void);
 
 /* Hypervisor TCP server */
-int hypervisor_tcp_server(int tcp_port);
+int hypervisor_tcp_server(char *ip_address,int tcp_port);
 
 #endif
