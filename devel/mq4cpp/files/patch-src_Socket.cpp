--- src/Socket.cpp.orig	Sat Jun 23 09:55:17 2007
+++ src/Socket.cpp	Sat Jun 23 09:58:16 2007
@@ -156,7 +156,7 @@
   } while  (IFRSIZE <= ifc.ifc_len);
 
   ifr = ifc.ifc_req;
-  for(; (ifr - ifc.ifc_req) * sizeof(ifreq) < static_cast<ulong>(ifc.ifc_len); ++ifr)
+  for(; (ifr - ifc.ifc_req) * sizeof(ifreq) < static_cast<unsigned long>(ifc.ifc_len); ++ifr)
   {
     if (ifr->ifr_addr.sa_data == (ifr+1)->ifr_addr.sa_data) continue;  // duplicate, skip it
 
@@ -168,7 +168,7 @@
     string ip = inet_ntoa(inaddrr(ifr_addr.sa_data));
 
     // ------ get HW_ADDRESS ------
-    if (ioctl(sockfd, SIOCGIFHWADDR, ifr) != 0) continue;  // failed to get mac, skip it
+    if (ioctl(sockfd, SIOCGIFMAC, ifr) != 0) continue;  // failed to get mac, skip it
 
 	string mac=string((char*)ifr->ifr_addr.sa_data,MAC_ADDRESS_CHAR_LEN);
 
