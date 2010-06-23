--- src/engine/e_network.c.orig	2010-06-23 09:39:36.000000000 +0200
+++ src/engine/e_network.c	2010-06-23 09:41:29.000000000 +0200
@@ -224,6 +224,12 @@
 
 	if(packet->flags&NET_PACKETFLAG_CONNLESS)
 	{
+		/* check the size of connless packet */
+		if(size < 6)
+		{
+			dbg_msg("", "connless packet too small, %d", size);
+			return -1;
+		}
 		packet->flags = NET_PACKETFLAG_CONNLESS;
 		packet->ack = 0;
 		packet->num_chunks = 0;
