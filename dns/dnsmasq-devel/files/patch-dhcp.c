Taken from upstream git repository
https://thekelleys.org.uk/gitweb/?p=dnsmasq.git;a=commitdiff;h=4333d5d93a8fb2c14ef3d9eefb1a13fb6ca8d9d5

Author: Johnny S. Lee (via mailing list)

--- ./src/dhcp.c.orig	2022-02-02 18:31:22 UTC
+++ ./src/dhcp.c
@@ -458,9 +458,12 @@ void dhcp_packet(time_t now, int pxe_fd)
   else 
     {
 #ifdef HAVE_DUMPFILE
-      dest.sin_addr.s_addr = (ntohs(mess->flags) & 0x8000) ? INADDR_BROADCAST : mess->yiaddr;
+      if (ntohs(mess->flags) & 0x8000)
+        dest.sin_addr.s_addr = INADDR_BROADCAST;
+      else
+        dest.sin_addr = mess->yiaddr;
       dest.sin_port = htons(daemon->dhcp_client_port);
-
+      
       dump_packet(DUMP_DHCP, (void *)iov.iov_base, iov.iov_len, NULL,
 		  (union mysockaddr *)&dest, daemon->dhcp_server_port);
 #endif
