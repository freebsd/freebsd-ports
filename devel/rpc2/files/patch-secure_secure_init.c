--- secure/secure_init.c.orig	Thu Oct  5 14:51:00 2006
+++ secure/secure_init.c	Thu Oct  5 14:52:06 2006
@@ -13,6 +13,8 @@
 			Additional copyrights
 #*/
 
+#include <netinet/in.h>  /* ``struct sockaddr_in'' in (at least) FreeBSD */
+
 #include <stdio.h>
 #include <string.h>
 #include <syslog.h>
