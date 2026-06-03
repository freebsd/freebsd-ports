--- external/corefx/src/Native/Unix/System.Native/pal_networkstatistics.c.orig	2020-05-11 17:58:42 UTC
+++ external/corefx/src/Native/Unix/System.Native/pal_networkstatistics.c
@@ -19,6 +19,7 @@
 
 #include <stdlib.h>
 #include <errno.h>
+#include <sys/socket.h>
 #include <net/route.h>
 #include <net/if.h>
 
@@ -27,6 +28,8 @@
 #include <sys/sysctl.h>
 #endif
 #include <sys/socketvar.h>
+#include <netinet/in.h>
+#include <netinet/in_pcb.h>
 #include <netinet/ip.h>
 #include <netinet/ip_icmp.h>
 #include <netinet/ip_var.h>
@@ -295,8 +298,7 @@ int32_t SystemNative_GetActiveTcpConnectionInfos(struc
     *infoCount = count;
 
     //  sizeof(struct xtcpcb) == 524
-    struct tcpcb tcp_pcb;
-    struct inpcb in_pcb;
+    struct xinpcb in_pcb;
     struct xinpgen* xHeadPtr;
     int32_t connectionIndex = -1;
     xHeadPtr = (struct xinpgen*)buffer;
@@ -307,11 +309,10 @@ int32_t SystemNative_GetActiveTcpConnectionInfos(struc
         connectionIndex++;
         struct xtcpcb* head_xtcpb = (struct xtcpcb*)xHeadPtr;
 
-        tcp_pcb = head_xtcpb->xt_tp;
         in_pcb = head_xtcpb->xt_inp;
 
         struct NativeTcpConnectionInformation* ntci = &infos[connectionIndex];
-        ntci->State = SystemNative_MapTcpState(tcp_pcb.t_state);
+        ntci->State = SystemNative_MapTcpState(head_xtcpb->t_state);
 
         uint8_t vflag = in_pcb.inp_vflag; // INP_IPV4 or INP_IPV6
         if ((vflag & INP_IPV4) == INP_IPV4)
@@ -393,7 +394,6 @@ int32_t SystemNative_GetActiveUdpListeners(struct IPEn
     }
     *infoCount = count;
 
-    struct inpcb in_pcb;
     struct xinpgen* xHeadPtr;
     int32_t connectionIndex = -1;
     xHeadPtr = (struct xinpgen*)buffer;
@@ -403,22 +403,21 @@ int32_t SystemNative_GetActiveUdpListeners(struct IPEn
     {
         connectionIndex++;
         struct xinpcb* head_xinpcb = (struct xinpcb*)xHeadPtr;
-        in_pcb = head_xinpcb->xi_inp;
         struct IPEndPointInfo* iepi = &infos[connectionIndex];
 
-        uint8_t vflag = in_pcb.inp_vflag; // INP_IPV4 or INP_IPV6
+        uint8_t vflag = head_xinpcb->inp_vflag; // INP_IPV4 or INP_IPV6
         if ((vflag & INP_IPV4) == INP_IPV4)
         {
-            memcpy_s(iepi->AddressBytes, sizeof_member(struct IPEndPointInfo, AddressBytes), &in_pcb.inp_laddr.s_addr, 4);
+            memcpy_s(iepi->AddressBytes, sizeof_member(struct IPEndPointInfo, AddressBytes), &head_xinpcb->inp_laddr.s_addr, 4);
             iepi->NumAddressBytes = 4;
         }
         else
         {
-            memcpy_s(iepi->AddressBytes, sizeof_member(struct IPEndPointInfo, AddressBytes), &in_pcb.in6p_laddr.s6_addr, 16);
+            memcpy_s(iepi->AddressBytes, sizeof_member(struct IPEndPointInfo, AddressBytes), &head_xinpcb->in6p_laddr.s6_addr, 16);
             iepi->NumAddressBytes = 16;
         }
 
-        iepi->Port = in_pcb.inp_lport;
+        iepi->Port = head_xinpcb->inp_lport;
     }
 
     free(buffer);
@@ -435,7 +434,7 @@ int32_t SystemNative_GetNativeIPInterfaceStatistics(ch
         return -1;
     }
 
-    int statisticsMib[] = {CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST2, 0};
+    int statisticsMib[] = {CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST, 0};
 
     size_t len;
     // Get estimated data length
@@ -464,12 +463,11 @@ int32_t SystemNative_GetNativeIPInterfaceStatistics(ch
          headPtr += ((struct if_msghdr*)headPtr)->ifm_msglen)
     {
         struct if_msghdr* ifHdr = (struct if_msghdr*)headPtr;
-        if (ifHdr->ifm_index == interfaceIndex && ifHdr->ifm_type == RTM_IFINFO2)
+        if (ifHdr->ifm_index == interfaceIndex && ifHdr->ifm_type == RTM_IFINFO)
         {
-            struct if_msghdr2* ifHdr2 = (struct if_msghdr2*)ifHdr;
-            retStats->SendQueueLength = (uint64_t)ifHdr2->ifm_snd_maxlen;
+            retStats->SendQueueLength = 0;
 
-            struct if_data64 systemStats = ifHdr2->ifm_data;
+            struct if_data systemStats = ifHdr->ifm_data;
             retStats->Mtu = systemStats.ifi_mtu;
             retStats->Speed = systemStats.ifi_baudrate; // bits per second.
             retStats->InPackets = systemStats.ifi_ipackets;
@@ -517,12 +515,12 @@ int32_t SystemNative_GetNumRoutes()
     }
 
     uint8_t* headPtr = buffer;
-    struct rt_msghdr2* rtmsg;
+    struct rt_msghdr* rtmsg;
     int32_t count = 0;
 
     for (size_t i = 0; i < len; i += rtmsg->rtm_msglen)
     {
-        rtmsg = (struct rt_msghdr2*)&buffer[i];
+        rtmsg = (struct rt_msghdr*)&buffer[i];
         if (rtmsg->rtm_flags & RTF_UP)
         {
             count++;
