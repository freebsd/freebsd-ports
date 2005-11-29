--- source/server.c.orig	Sun Jun 19 01:34:12 2005
+++ source/server.c	Sun Mar 20 00:41:53 2005
@@ -1552,6 +1552,8 @@
 		    arg6, arg7, arg8, arg9, arg10);
 #endif
 		Euc2Jis(buffer, buffer2);
+		if (buffer2[strlen(buffer2) - 1] == ' ')
+		    buffer2[strlen(buffer2) - 1] = '\0';
 
 		len = strlen(buffer2);
 		if (len > (IRCD_BUFFER_SIZE - 2))
