--- lib/network.c.orig	2007-12-07 20:46:47.000000000 +0530
+++ lib/network.c	2007-12-23 22:45:38.000000000 +0530
@@ -1261,8 +1261,10 @@
 	ssl_free_client_credentials(s->ssl_credentials);
 #endif
 
-	g_iconv_close(s->connection.incoming_iconv);
-	g_iconv_close(s->connection.outgoing_iconv);
+	if (s->connection.incoming_iconv != (GIConv)-1)
+		g_iconv_close(s->connection.incoming_iconv);
+	if (s->connection.outgoing_iconv != (GIConv)-1)
+		g_iconv_close(s->connection.outgoing_iconv);
 
 	g_free(s);
 }
