X-Git-Url: http://thekelleys.org.uk/gitweb/?p=dnsmasq.git;a=blobdiff_plain;f=src%2Ftftp.c;h=c618a2c1eeb73de147ade0cf75de24cbc3cb3f38;hp=435b21687ffa366a7bebf1bfc7905997be5b8f7d;hb=936bd82755e8f75fc09c1e9a67fb390175b157d4;hpb=13a58f9590a7071ad4a8c8f7e4178c29a6b66be3

--- src/tftp.c.orig	2018-10-18 18:21:55 UTC
+++ src/tftp.c
@@ -74,9 +74,11 @@ void tftp_request(struct listener *listen, time_t now)
 #if defined(HAVE_LINUX_NETWORK)
     char control[CMSG_SPACE(sizeof(struct in_pktinfo))];
 #elif defined(HAVE_SOLARIS_NETWORK)
-    char control[CMSG_SPACE(sizeof(unsigned int))];
+    char control[CMSG_SPACE(sizeof(struct in_addr)) +
+		 CMSG_SPACE(sizeof(unsigned int))];
 #elif defined(IP_RECVDSTADDR) && defined(IP_RECVIF)
-    char control[CMSG_SPACE(sizeof(struct sockaddr_dl))];
+    char control[CMSG_SPACE(sizeof(struct in_addr)) +
+		 CMSG_SPACE(sizeof(struct sockaddr_dl))];
 #endif
   } control_u; 
 
