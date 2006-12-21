$FreeBSD$

--- prepare_pcap.c.orig
+++ prepare_pcap.c
@@ -19,7 +19,7 @@
 #include <stdlib.h>
 #include <netinet/in.h>
 #include <netinet/udp.h>
-#if defined(__HPUX) || defined(__CYGWIN)
+#if defined(__HPUX) || defined(__CYGWIN) || defined(__FreeBSD__)
 #include <netinet/in_systm.h>
 #endif
 #include <netinet/ip.h>
@@ -142,7 +142,7 @@
         fprintf(stderr, "prepare_pcap.c: Ignoring non UDP packet!\n");
         continue;
       }
-#if defined(__DARWIN) || defined(__CYGWIN)
+#if defined(__DARWIN) || defined(__CYGWIN) || defined(__FreeBSD__)
       udphdr = (struct udphdr *)((char *)iphdr + (iphdr->ihl << 2) + 4);
       pktlen = (u_long)(ntohs(udphdr->uh_ulen));
 #else
@@ -164,7 +164,7 @@
       ERROR("Can't allocate memory for pcap pkt data");
     memcpy(pkt_index->data, udphdr, pktlen);
 
-#if defined(__HPUX) || defined(__DARWIN) || (defined __CYGWIN)
+#if defined(__HPUX) || defined(__DARWIN) || (defined __CYGWIN) || defined(__FreeBSD__)
     udphdr->uh_sum = 0 ;      
 #else
     udphdr->check = 0;
@@ -173,14 +173,14 @@
       // compute a partial udp checksum
       // not including port that will be changed
       // when sending RTP
-#if defined(__HPUX) || defined(__DARWIN) || (defined __CYGWIN)
+#if defined(__HPUX) || defined(__DARWIN) || (defined __CYGWIN) || defined(__FreeBSD__)
     pkt_index->partial_check = check((u_int16_t *) &udphdr->uh_ulen, pktlen - 4) + ntohs(IPPROTO_UDP + pktlen);
 #else
     pkt_index->partial_check = check((u_int16_t *) &udphdr->len, pktlen - 4) + ntohs(IPPROTO_UDP + pktlen);
 #endif
     if (max_length < pktlen)
       max_length = pktlen;
-#if defined(__HPUX) || defined(__DARWIN) || (defined __CYGWIN)
+#if defined(__HPUX) || defined(__DARWIN) || (defined __CYGWIN) || defined(__FreeBSD__)
     if (base > ntohs(udphdr->uh_dport))
       base = ntohs(udphdr->uh_dport);
 #else
