--- gen_eth.c.orig	Wed Oct 18 22:39:46 2006
+++ gen_eth.c	Wed Oct 18 22:39:55 2006
@@ -46,7 +46,7 @@
       goto pcap_error;
 
    /* Accept only incoming packets */
-   pcap_setdirection(p,PCAP_D_IN);
+   pcap_setdirection(p,D_IN);
 #else
    p = pcap_open(device,2048,
                  PCAP_OPENFLAG_PROMISCUOUS | 
