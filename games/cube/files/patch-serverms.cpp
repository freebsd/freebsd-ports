--- serverms.cpp.orig	2005-08-11 06:02:46.000000000 +0400
+++ serverms.cpp	2009-12-18 05:09:20.000000000 +0300
@@ -13,7 +13,7 @@
         if(ad.host==ENET_HOST_ANY) return;
     };
     if(mssock!=ENET_SOCKET_NULL) enet_socket_destroy(mssock);
-    mssock = enet_socket_create(ENET_SOCKET_TYPE_STREAM, NULL);
+    mssock = enet_socket_create(ENET_SOCKET_TYPE_STREAM);
     if(mssock==ENET_SOCKET_NULL) { printf("could not open socket\n"); return; };
     if(enet_socket_connect(mssock, &ad)<0) { printf("could not connect\n"); return; };
     ENetBuffer buf;
@@ -135,7 +135,8 @@
 	if(listen)
 	{
         ENetAddress address = { ENET_HOST_ANY, CUBE_SERVINFO_PORT };
-        pongsock = enet_socket_create(ENET_SOCKET_TYPE_DATAGRAM, &address);
+        pongsock = enet_socket_create(ENET_SOCKET_TYPE_DATAGRAM);
         if(pongsock == ENET_SOCKET_NULL) fatal("could not create server info socket\n");
+		if(enet_socket_bind(pongsock, &address) == -1) fatal("cannot bind server info socket\n");
 	};
 };
