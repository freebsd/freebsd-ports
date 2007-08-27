--- icbirc.c.orig	Fri Nov 19 06:14:28 2004
+++ icbirc.c	Tue Aug 28 05:12:05 2007
@@ -322,8 +322,8 @@
 	    (unsigned long)(time(NULL) - t), bytes_out, bytes_in);
 	if (terminate_client)
 		irc_send_notice(client_fd, "Closing connection "
-		    "(%u seconds, %lu:%lu bytes)",
-		    time(NULL) - t, bytes_out, bytes_in);
+		    "(%lu seconds, %lu:%lu bytes)",
+		     (unsigned long)(time(NULL) - t), bytes_out, bytes_in);
 }
 
 int
