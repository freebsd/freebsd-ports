--- tftpd.h.orig	2004-02-27 10:05:26.000000000 +0800
+++ tftpd.h	2013-10-30 13:25:35.000000000 +0800
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
 
@@ -93,7 +98,7 @@
 /*
  * Defined in tftpd_list.c, operation on client structure list.
  */
-inline void tftpd_clientlist_ready(struct thread_data *thread);
+void tftpd_clientlist_ready(struct thread_data *thread);
 void tftpd_clientlist_remove(struct thread_data *thread,
                              struct client_info *client);
 void tftpd_clientlist_free(struct thread_data *thread);
