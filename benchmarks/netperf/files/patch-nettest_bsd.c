--- nettest_bsd.c.orig	Tue Sep 21 22:33:40 2004
+++ nettest_bsd.c	Thu Nov 18 23:29:38 2004
@@ -7649,7 +7649,9 @@
   else {
     tcp_tran_rr_request->test_length	=	test_trans * -1;
   }
-  
+  tcp_tran_rr_request->port             =       remote_data_port;
+  tcp_tran_rr_request->ipaddress        =       remote_data_ip;
+
   if (debug > 1) {
     fprintf(where,"netperf: send_tcp_tran_rr: requesting TCP_TRR test\n");
   }
@@ -7753,9 +7755,11 @@
     /* all depends on "reality of programming." keeping it this way is */
     /* a bit more conservative I imagine - raj 3/95 */
     send_socket = create_data_socket(AF_INET, 
-				     SOCK_STREAM);
+				     SOCK_STREAM,
+				     local_data_ip,
+				     local_data_port);
   
-    if (send_socket == INAVLID_SOCKET) {
+    if (send_socket == INVALID_SOCKET) {
       perror("netperf: send_tcp_tran_rr: tcp stream data socket");
       exit(1);
     }
@@ -8219,7 +8223,9 @@
   loc_sndavoid = tcp_tran_rr_request->so_sndavoid;
   
   s_listen = create_data_socket(AF_INET,
-				SOCK_STREAM);
+				SOCK_STREAM,
+				tcp_tran_rr_request->ipaddress,
+				tcp_tran_rr_request->port);
   
   if (s_listen == INVALID_SOCKET) {
     netperf_response.content.serv_errno = errno;
@@ -8438,7 +8444,7 @@
 			  send_message_ptr,
 			  tcp_tran_rr_request->response_size,
 			  MSG_EOF,
-			  &peeraddr_in,
+			  (struct sockaddr *)&peeraddr_in,
 			  sizeof(struct sockaddr_in))) == SOCKET_ERROR) {
       if (SOCKET_EINTR(bytes_sent)) {
 	/* the test timer has popped */
