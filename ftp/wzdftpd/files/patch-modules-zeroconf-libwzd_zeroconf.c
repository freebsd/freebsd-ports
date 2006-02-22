--- modules/zeroconf/libwzd_zeroconf.c.orig	Wed Feb 22 21:44:51 2006
+++ modules/zeroconf/libwzd_zeroconf.c	Wed Feb 22 21:45:26 2006
@@ -27,6 +27,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <string.h>
+#include <signal.h>
 
 #include <arpa/inet.h> /* htonl() */
 #include <sys/wait.h>
