--- gen_eth.c.orig	2007-05-26 18:52:33.000000000 +0900
+++ gen_eth.c	2009-07-21 03:18:35.194759073 +0900
@@ -22,6 +22,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/wait.h>
+#include <sys/ioctl.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <pthread.h>
@@ -45,8 +46,13 @@
    if (!(p = pcap_open_live(device,2048,TRUE,10,pcap_errbuf)))
       goto pcap_error;
 
-   /* Accept only incoming packets */
-   pcap_setdirection(p,PCAP_D_IN);
+   pcap_setdirection(p,PCAP_D_INOUT);
+#ifdef BIOCFEEDBACK
+   {
+     int on = 1;
+     ioctl(pcap_fileno(p), BIOCFEEDBACK, &on);
+   }
+#endif
 #else
    p = pcap_open(device,2048,
                  PCAP_OPENFLAG_PROMISCUOUS | 
