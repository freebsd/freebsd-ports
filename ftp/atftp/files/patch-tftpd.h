--- tftpd.h.orig	2010-10-11 11:33:53.000000000 +0800
+++ tftpd.h	2010-10-11 11:34:33.000000000 +0800
@@ -71,6 +71,11 @@
 struct client_info {
      struct sockaddr_in client;
      int done;                  /* that client as receive it's file */
+     int bytes_sent;
+     int number_of_timeout;     /* number of timeouts while sending to 
+                                 * this client
+                                 */
+     int last_ack;              /* last ACK received from this client */
      struct client_info *next;
 };
 
