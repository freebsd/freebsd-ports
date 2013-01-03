This patch adds support for IFT_L2VLAN interfaces in the
FreeBSD implementation of NetIfList(), treating them
identically as IFT_ETHER interfaces.

Submitted by:	Landon J Fuller <landonf at plausible dot coop>
Sponsored by:	Plausible Labs Cooperative, Inc
--- src/VBox/Main/src-server/freebsd/NetIf-freebsd.cpp.orig	2012-04-10 11:28:41.552067907 -0400
+++ src/VBox/Main/src-server/freebsd/NetIf-freebsd.cpp	2012-04-10 11:28:45.872069027 -0400
@@ -268,7 +268,7 @@
             pNext += pIfAddrMsg->ifam_msglen;
         }
 
-        if (pSdl->sdl_type == IFT_ETHER)
+        if (pSdl->sdl_type == IFT_ETHER || pSdl->sdl_type == IFT_L2VLAN)
         {
             struct ifreq IfReq;
             strcpy(IfReq.ifr_name, pNew->szShortName);
@@ -373,7 +373,7 @@
             pNext += pIfAddrMsg->ifam_msglen;
         }
 
-        if (!fSkip && pSdl->sdl_type == IFT_ETHER)
+        if (!fSkip && (pSdl->sdl_type == IFT_ETHER || pSdl->sdl_type == IFT_L2VLAN))
         {
             size_t cbNameLen = pSdl->sdl_nlen + 1;
             memcpy(pInfo->MACAddress.au8, LLADDR(pSdl), sizeof(pInfo->MACAddress.au8));
