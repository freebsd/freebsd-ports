--- src/packet.c.orig	Tue Nov 16 22:29:48 2004
+++ src/packet.c	Sun Feb 13 12:33:49 2005
@@ -532,7 +532,7 @@
 
   /* Check to make sure we're not flooding */
 
-  if (IsPerson(client_p) &&
+  if (!(IsServer(client_p) || IsHandshake(client_p) || IsConnecting(client_p)) &&
       (linebuf_alloclen(&client_p->localClient->buf_recvq) >
        ConfigFileEntry.client_flood))
   {
