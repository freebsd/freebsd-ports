
$FreeBSD$

--- icbirc.c.orig	Wed Aug 20 23:55:59 2003
+++ icbirc.c	Sat Feb 14 23:09:01 2004
@@ -318,12 +318,12 @@
 done:
 	if (server_fd >= 0)
 		close(server_fd);
-	printf("(%u seconds, %lu:%lu bytes)\n",
-	    time(NULL) - t, bytes_out, bytes_in);
+	printf("(%lu seconds, %lu:%lu bytes)\n",
+	    (long)time(NULL) - t, bytes_out, bytes_in);
 	if (terminate_client)
 		irc_send_notice(client_fd, "Closing connection "
-		    "(%u seconds, %lu:%lu bytes)",
-		    time(NULL) - t, bytes_out, bytes_in);
+		    "(%lu seconds, %lu:%lu bytes)",
+		    (long)time(NULL) - t, bytes_out, bytes_in);
 }
 
 int
