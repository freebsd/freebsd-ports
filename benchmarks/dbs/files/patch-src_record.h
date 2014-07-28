--- src/record.h.orig	1997-10-13 09:36:38.000000000 +0900
+++ src/record.h	2012-04-29 03:08:53.000000000 +0900
@@ -69,7 +69,9 @@
 #include <netinet/tcp.h>
 
 #ifndef __linux__
+#ifndef __FreeBSD__
 #include <netinet/in_pcb.h>
+#endif
 #include <netinet/ip_var.h>
 #include <netinet/tcpip.h>
 /*#define TCPSTATES*/
