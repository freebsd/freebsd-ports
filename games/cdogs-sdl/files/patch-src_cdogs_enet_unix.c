--- src/cdogs/enet/unix.c.orig	2020-06-16 13:26:23 UTC
+++ src/cdogs/enet/unix.c
@@ -300,7 +300,7 @@ enet_socket_listen (ENetSocket socket, int backlog)
 ENetSocket
 enet_socket_create (ENetSocketType type)
 {
-    return socket (PF_INET, type == ENET_SOCKET_TYPE_DATAGRAM ? SOCK_DGRAM : SOCK_STREAM, 0);
+    return socket (AF_INET, type == ENET_SOCKET_TYPE_DATAGRAM ? SOCK_DGRAM : SOCK_STREAM, 0);
 }
 
 int
