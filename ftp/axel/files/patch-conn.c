--- conn.c.orig	Sun Aug  5 23:44:46 2001
+++ conn.c	Sun Aug  5 23:45:38 2001
@@ -121,6 +121,13 @@
 	/* Take default port numbers from /etc/services			*/
 	else
 	{
+#ifdef DARWIN
+		/* don't want to include a NetInfo interface */
+		if( conn->proto == PROTO_FTP )
+			conn->port = 21;
+		else
+			conn->port = 80;
+#else
 		struct servent *serv;
 		
 		/* Never assume the standard 21/80 ports!!		*/
@@ -130,6 +137,7 @@
 			serv = getservbyname( "www", "tcp" );
 		
 		conn->port = ntohs( serv->s_port );
+#endif
 	}
 	
 	return( conn->port > 0 );
