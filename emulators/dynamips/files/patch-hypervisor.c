--- hypervisor.c.orig	Wed Mar 21 11:11:12 2007
+++ hypervisor.c	Wed Mar 21 11:29:55 2007
@@ -535,7 +535,7 @@
 }
 
 /* Hypervisor TCP server */
-int hypervisor_tcp_server(int tcp_port)
+int hypervisor_tcp_server(char* ip_address,int tcp_port)
 {
    int fd_array[HYPERVISOR_MAX_FD];
    struct sockaddr_storage remote_addr;
@@ -565,7 +565,7 @@
    if (!tcp_port)
       tcp_port = HYPERVISOR_TCP_PORT;
 
-   fd_count = ip_listen(tcp_port,SOCK_STREAM,HYPERVISOR_MAX_FD,fd_array);
+   fd_count = ip_listen(ip_address,tcp_port,SOCK_STREAM,HYPERVISOR_MAX_FD,fd_array);
 
    if (fd_count <= 0) {
       fprintf(stderr,"Hypervisor: unable to create TCP sockets.\n");
