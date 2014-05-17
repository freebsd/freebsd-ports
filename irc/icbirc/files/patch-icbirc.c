--- icbirc.c.orig	2004-11-19 06:14:28.000000000 +0900
+++ icbirc.c	2014-05-17 02:17:15.000000000 +0900
@@ -30,7 +30,9 @@
  *
  */
 
+#if 0
 static const char rcsid[] = "$Id: icbirc.c,v 1.13 2004/11/18 21:14:28 dhartmei Exp $";
+#endif
 
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -322,8 +324,8 @@
 	    (unsigned long)(time(NULL) - t), bytes_out, bytes_in);
 	if (terminate_client)
 		irc_send_notice(client_fd, "Closing connection "
-		    "(%u seconds, %lu:%lu bytes)",
-		    time(NULL) - t, bytes_out, bytes_in);
+		    "(%lu seconds, %lu:%lu bytes)",
+		     (unsigned long)(time(NULL) - t), bytes_out, bytes_in);
 }
 
 int
