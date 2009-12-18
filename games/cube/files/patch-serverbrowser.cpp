--- serverbrowser.cpp.orig	2004-05-09 19:20:40.000000000 +0400
+++ serverbrowser.cpp	2009-12-18 05:07:23.000000000 +0300
@@ -268,7 +268,7 @@
 {
     if(pingsock == ENET_SOCKET_NULL)
     {
-        pingsock = enet_socket_create(ENET_SOCKET_TYPE_DATAGRAM, NULL);
+        pingsock = enet_socket_create(ENET_SOCKET_TYPE_DATAGRAM);
         resolverinit(1, 1000);
     };
     resolverclear();
