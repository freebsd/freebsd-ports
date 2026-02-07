--- code/qcommon/net_ip.c.orig	2008-06-21 15:22:13.000000000 -0300
+++ code/qcommon/net_ip.c	2008-06-21 15:22:26.000000000 -0300
@@ -55,14 +55,14 @@
 #	define _BSD_SOCKLEN_T_
 #endif
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #include <errno.h>
 #include <netdb.h>
 #include <netinet/in.h>
 #include <net/if.h>
 #include <sys/ioctl.h>
-#include <sys/socket.h>
-#include <sys/types.h>
 #include <sys/time.h>
 #include <unistd.h>
 #if !defined(__sun) && !defined(__sgi)
