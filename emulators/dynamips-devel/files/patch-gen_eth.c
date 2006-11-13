--- gen_eth.c.orig	Thu Sep 14 17:59:13 2006
+++ gen_eth.c	Tue Nov 14 00:28:18 2006
@@ -25,6 +25,13 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <pthread.h>
+#ifdef __FreeBSD__
+#include <osreldate.h>
+
+#if __FreeBSD_version < 602100 || __FreeBSD_version < 700021
+#define PCAP_D_IN D_IN
+#endif
+#endif
 
 #ifdef CYGWIN
 /* Needed for pcap_open() flags */
