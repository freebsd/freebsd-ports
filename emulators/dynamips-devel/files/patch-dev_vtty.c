--- dev_vtty.c.orig	Fri Sep  7 12:03:11 2007
+++ dev_vtty.c	Fri Sep 14 10:24:02 2007
@@ -24,6 +24,8 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <assert.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 
 #include <arpa/telnet.h>
 
@@ -43,6 +45,8 @@
 #include "dev_c2600.h"
 #include "dev_vtty.h"
 
+extern char *hypervisor_ip_address;
+
 /* VTTY list */
 static pthread_mutex_t vtty_list_mutex = PTHREAD_MUTEX_INITIALIZER;
 static vtty_t *vtty_list = NULL;
@@ -132,7 +136,8 @@
 
    memset(&serv,0,sizeof(serv));
    serv.sin_family = AF_INET;
-   serv.sin_addr.s_addr = htonl(INADDR_ANY);
+   if (hypervisor_ip_address && strlen(hypervisor_ip_address))
+      serv.sin_addr.s_addr = inet_addr(hypervisor_ip_address);
    serv.sin_port = htons(vtty->tcp_port);
 
    if (bind(vtty->accept_fd,(struct sockaddr *)&serv,sizeof(serv)) < 0) {
