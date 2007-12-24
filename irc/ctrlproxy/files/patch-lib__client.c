--- lib/client.c.orig	2007-12-07 20:46:47.000000000 +0530
+++ lib/client.c	2007-12-23 22:08:20.000000000 +0530
@@ -277,8 +277,10 @@
 	
 	c->incoming = NULL;
 
-	g_iconv_close(c->outgoing_iconv);
-	g_iconv_close(c->incoming_iconv);
+	if (c->outgoing_iconv != (GIConv)-1)
+		g_iconv_close(c->outgoing_iconv);
+	if (c->incoming_iconv != (GIConv)-1)
+		g_iconv_close(c->incoming_iconv);
 
 	if (c->exit_on_close) 
 		exit(0);
