--- net.c.orig	Wed Mar 21 11:34:17 2007
+++ net.c	Wed Mar 21 11:55:29 2007
@@ -353,7 +353,7 @@
 
 #if HAS_RFC2553
 /* Listen on the specified port */
-int ip_listen(int port,int sock_type,int max_fd,int fd_array[])
+int ip_listen(char *ip_address,int port,int sock_type,int max_fd,int fd_array[])
 {
    struct addrinfo hints,*res,*res0;
    char port_str[20];
@@ -370,7 +370,7 @@
 
    snprintf(port_str,sizeof(port_str),"%d",port);
 
-   if ((error = getaddrinfo(NULL,port_str,&hints,&res0)) != 0) {
+   if ((error = getaddrinfo((strlen(ip_address)==0)?NULL:ip_address,port_str,&hints,&res0)) != 0) {
       fprintf(stderr,"ip_listen: %s", gai_strerror(error));
       return(-1);
    }
@@ -405,7 +405,7 @@
 }
 #else
 /* Listen on the specified port */
-int ip_listen(int port,int sock_type,int max_fd,int fd_array[])
+int ip_listen(char *ip_address,int port,int sock_type,int max_fd,int fd_array[])
 {
    struct sockaddr_in sin;
    int i,sck,reuse=1;
@@ -422,6 +422,8 @@
    memset(&sin,0,sizeof(sin));
    sin.sin_family = PF_INET;
    sin.sin_port   = htons(port);
+   if (strlen(ip_address) != 0 && inet_addr(ip_address) != INADDR_NONE) 
+	   sin.sin_addr = inet_addr(ip_address);
 
    setsockopt(fd_array[0],SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
 
