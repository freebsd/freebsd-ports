--- chrome/browser/media/router/discovery/discovery_network_list_posix.cc.orig	2021-01-07 00:36:23 UTC
+++ chrome/browser/media/router/discovery/discovery_network_list_posix.cc
@@ -10,6 +10,7 @@
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/time.h>
 
 #include <algorithm>
 
@@ -18,7 +19,7 @@
 #include "chrome/browser/media/router/discovery/discovery_network_list_wifi.h"
 #include "net/base/net_errors.h"
 
-#if !defined(OS_MAC)
+#if !defined(OS_MAC) && !defined(OS_BSD)
 #include <netpacket/packet.h>
 #else
 #include <net/if_dl.h>
@@ -27,12 +28,12 @@
 namespace media_router {
 namespace {
 
-#if !defined(OS_MAC)
+#if !defined(OS_MAC) && !defined(OS_BSD)
 using sll = struct sockaddr_ll;
 #define SOCKET_ARP_TYPE(s) ((s)->sll_hatype)
 #define SOCKET_ADDRESS_LEN(s) ((s)->sll_halen)
 #define SOCKET_ADDRESS(s) ((s)->sll_addr)
-#else  // defined(OS_MAC)
+#else  // defined(OS_MAC) || defined(OS_BSD)
 #define AF_PACKET AF_LINK
 using sll = struct sockaddr_dl;
 #define SOCKET_ARP_TYPE(s) ((s)->sdl_type)
