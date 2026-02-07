--- common/net_msg.c.orig	Mon Jul 24 15:18:19 2006
+++ common/net_msg.c	Mon Jul 24 16:38:29 2006
@@ -134,7 +134,7 @@
 {
 	byte	*buf;
 
-	assert (!(c < -128 || c > 127));
+	//assert (!(c < -128 || c > 127));
 
 	buf = MSG_GetWriteSpace (dest, 1);
 	buf[0] = c;
