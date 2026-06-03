--- third_party/moonlight-common-c/enet/host.c.orig	2025-11-10 02:29:40 UTC
+++ third_party/moonlight-common-c/enet/host.c
@@ -3,6 +3,7 @@
  @brief ENet host management functions
 */
 #define ENET_BUILDING_LIB 1
+#include <netinet/in.h>
 #include <string.h>
 #include "enet/enet.h"
 
@@ -50,7 +51,17 @@ enet_host_create (int addressFamily, const ENetAddress
     memset (host -> peers, 0, peerCount * sizeof (ENetPeer));
 
     host -> socket = enet_socket_create (addressFamily, ENET_SOCKET_TYPE_DATAGRAM);
+    #if defined(IP_SENDSRCADDR)
+    // if want use IP_SENDSRCADDR with udp socket, FreeBSD need INADDR_ANY addr and local port.
+    ENetAddress localAddress = * address;
+    if (address != NULL && addressFamily == AF_INET) {
+      struct sockaddr_in *addr = (struct sockaddr_in *) & localAddress.address;
+      addr -> sin_addr.s_addr = htonl(INADDR_ANY);
+    }
+    if (host -> socket == ENET_SOCKET_NULL || (address != NULL && enet_socket_bind (host -> socket, & localAddress) < 0))
+    #else
     if (host -> socket == ENET_SOCKET_NULL || (address != NULL && enet_socket_bind (host -> socket, address) < 0))
+    #endif
     {
        if (host -> socket != ENET_SOCKET_NULL)
          enet_socket_destroy (host -> socket);
@@ -65,8 +76,24 @@ enet_host_create (int addressFamily, const ENetAddress
     enet_socket_set_option (host -> socket, ENET_SOCKOPT_RCVBUF, ENET_HOST_RECEIVE_BUFFER_SIZE);
     enet_socket_set_option (host -> socket, ENET_SOCKOPT_SNDBUF, ENET_HOST_SEND_BUFFER_SIZE);
 
-    if (address != NULL && enet_socket_get_address (host -> socket, & host -> address) < 0)   
-      host -> address = * address;
+    if (address != NULL)
+    {
+      #if defined(IP_SENDSRCADDR)
+      // if no connect to host->socket,INADDR_ANY socket is bind to 0.0.0.0,so use address directly
+      if (addressFamily == AF_INET) {
+        enet_socket_get_address (host -> socket, & localAddress);
+        ((struct sockaddr_in *) & address -> address) -> sin_port = ((struct sockaddr_in *) & localAddress.address) -> sin_port;
+        host -> address = * address;
+      }
+      else
+      #endif
+      {
+        if (enet_socket_get_address (host -> socket, & host -> address) < 0)
+        {
+          host -> address = * address;
+        }
+      }
+    }
 
     if (! channelLimit || channelLimit > ENET_PROTOCOL_MAXIMUM_CHANNEL_COUNT)
       channelLimit = ENET_PROTOCOL_MAXIMUM_CHANNEL_COUNT;
