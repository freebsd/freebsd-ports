--- ./qcommon/common.c.orig	Tue May 16 15:20:10 2006
+++ ./qcommon/common.c	Tue May 16 15:20:10 2006
@@ -781,7 +781,9 @@
 	l = 0;
 	do
 	{
-		c = MSG_ReadChar (msg_read);
+		// sku - replaced MSG_ReadChar with MSG_ReadByte to avoid
+		// potentional vulnerability
+		c = MSG_ReadByte (msg_read);
 		if (c == -1 || c == 0)
 			break;
 		string[l] = c;
@@ -801,7 +803,9 @@
 	l = 0;
 	do
 	{
-		c = MSG_ReadChar (msg_read);
+		// sku - replaced MSG_ReadChar with MSG_ReadByte to avoid
+		// potentional vulnerability
+		c = MSG_ReadByte (msg_read);
 		if (c == -1 || c == 0 || c == '\n')
 			break;
 		string[l] = c;
