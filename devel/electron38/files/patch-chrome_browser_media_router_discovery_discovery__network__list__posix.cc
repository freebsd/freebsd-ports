--- chrome/browser/media/router/discovery/discovery_network_list_posix.cc.orig	2024-10-16 21:30:58 UTC
+++ chrome/browser/media/router/discovery/discovery_network_list_posix.cc
@@ -10,11 +10,12 @@
 #include "chrome/browser/media/router/discovery/discovery_network_list.h"
 
 #include <ifaddrs.h>
+#include <sys/socket.h>
+#include <sys/types.h>
+#include <sys/time.h>
 #include <net/if.h>
 #include <net/if_arp.h>
 #include <netinet/in.h>
-#include <sys/socket.h>
-#include <sys/types.h>
 
 #include <algorithm>
 
@@ -23,7 +24,7 @@
 #include "chrome/browser/media/router/discovery/discovery_network_list_wifi.h"
 #include "net/base/net_errors.h"
 
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 #include <netpacket/packet.h>
 #else
 #include <net/if_dl.h>
@@ -32,7 +33,7 @@ namespace {
 namespace media_router {
 namespace {
 
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 using sll = struct sockaddr_ll;
 #define SOCKET_ARP_TYPE(s) ((s)->sll_hatype)
 #define SOCKET_ADDRESS_LEN(s) ((s)->sll_halen)
@@ -43,6 +44,12 @@ using sll = struct sockaddr_dl;
 #define SOCKET_ARP_TYPE(s) ((s)->sdl_type)
 #define SOCKET_ADDRESS_LEN(s) ((s)->sdl_alen)
 #define SOCKET_ADDRESS(s) (LLADDR(s))
+#endif
+
+#if BUILDFLAG(IS_BSD)
+bool MaybeGetWifiSSID(const std::string& if_name, std::string* ssid_out) {
+  return false;
+}
 #endif
 
 void GetDiscoveryNetworkInfoListImpl(
