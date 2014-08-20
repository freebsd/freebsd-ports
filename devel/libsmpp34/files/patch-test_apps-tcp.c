--- test_apps/tcp.c.orig	2014-07-11 16:22:27.000000000 +0300
+++ test_apps/tcp.c	2014-07-11 16:33:16.000000000 +0300
@@ -33,12 +33,15 @@
 
 #include "esme.h"
 
+#include <sys/socket.h>
+#include <netinet/in.h>
+
 int do_tcp_connect( xmlNodePtr p, int *s )
 {
     int ret = 0;
     int n = 1;
     struct hostent _host;
-#ifdef __linux__
+#ifdef __FreeBSD__
     struct hostent *__host_result;
 #endif
     struct in_addr addr;
@@ -61,7 +64,7 @@ int do_tcp_connect( xmlNodePtr p, int *s
         ret = -1; goto lb_tcp_connect_end;
     };
 
-#ifdef __linux__
+#ifdef __FreeBSD__
     if( gethostbyname_r(h,&_host,ahost,sizeof(ahost),&__host_result,&n) != 0)
 #else /* solaris */
     if( gethostbyname_r(h,&_host,ahost,sizeof(ahost),&n) == NULL)
