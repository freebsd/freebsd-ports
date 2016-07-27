--- src/record.h.orig	1997-10-13 00:36:38 UTC
+++ src/record.h
@@ -69,7 +69,9 @@
 #include <netinet/tcp.h>
 
 #ifndef __linux__
+#ifndef __FreeBSD__
 #include <netinet/in_pcb.h>
+#endif
 #include <netinet/ip_var.h>
 #include <netinet/tcpip.h>
 /*#define TCPSTATES*/
