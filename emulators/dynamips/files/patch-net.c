--- net.c.orig	2007-05-26 18:52:33.000000000 +0900
+++ net.c	2009-07-21 03:16:45.891581213 +0900
@@ -208,6 +208,7 @@
       addr->eth_addr_byte[3] = v[1] & 0xFF;
       addr->eth_addr_byte[4] = (v[2] >> 8) & 0xFF;
       addr->eth_addr_byte[5] = v[2] & 0xFF;
+      return(0);
    }
 
    return(-1);
@@ -353,7 +354,7 @@
 
 #if HAS_RFC2553
 /* Listen on the specified port */
-int ip_listen(int port,int sock_type,int max_fd,int fd_array[])
+int ip_listen(char *ip_address,int port,int sock_type,int max_fd,int fd_array[])
 {
    struct addrinfo hints,*res,*res0;
    char port_str[20];
@@ -370,7 +371,7 @@
 
    snprintf(port_str,sizeof(port_str),"%d",port);
 
-   if ((error = getaddrinfo(NULL,port_str,&hints,&res0)) != 0) {
+   if ((error = getaddrinfo((strlen(ip_address)==0)?NULL:ip_address,port_str,&hints,&res0)) != 0) {
       fprintf(stderr,"ip_listen: %s", gai_strerror(error));
       return(-1);
    }
@@ -405,7 +406,7 @@
 }
 #else
 /* Listen on the specified port */
-int ip_listen(int port,int sock_type,int max_fd,int fd_array[])
+int ip_listen(char *ip_address,int port,int sock_type,int max_fd,int fd_array[])
 {
    struct sockaddr_in sin;
    int i,sck,reuse=1;
@@ -422,6 +423,8 @@
    memset(&sin,0,sizeof(sin));
    sin.sin_family = PF_INET;
    sin.sin_port   = htons(port);
+   if (strlen(ip_address) != 0 && inet_addr(ip_address) != INADDR_NONE) 
+	   sin.sin_addr = inet_addr(ip_address);
 
    setsockopt(fd_array[0],SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
 
