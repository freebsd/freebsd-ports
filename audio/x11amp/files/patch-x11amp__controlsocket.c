--- ./x11amp/controlsocket.c.orig	1999-04-11 23:26:04.000000000 +0000
+++ ./x11amp/controlsocket.c	2013-12-02 19:13:07.000000000 +0000
@@ -178,7 +178,7 @@
 				if(!select(fd+1,&set,NULL,NULL,&tv))
 				{
 					close(fd);
-					return;
+					pthread_exit(NULL);
 				}
 				pkt = g_malloc0(sizeof(PacketNode));
 				read(fd,&pkt->hdr,sizeof(ClientPktHeader));
