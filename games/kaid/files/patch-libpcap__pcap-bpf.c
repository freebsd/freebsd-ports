--- libpcap/pcap-bpf.c.orig	Fri Nov 21 19:06:28 2003
+++ libpcap/pcap-bpf.c	Thu Mar  3 13:03:28 2005
@@ -467,7 +467,7 @@
 	 */
 	do {
 		(void)snprintf(device, sizeof(device), "/dev/bpf%d", n++);
-		fd = open(device, O_RDONLY);
+		fd = open(device, O_RDWR);
 	} while (fd < 0 && errno == EBUSY);
 
 	/*
