--- nettest_ipv6.c.orig	Tue Sep 21 22:33:40 2004
+++ nettest_ipv6.c	Thu Nov 18 23:32:10 2004
@@ -6371,7 +6371,7 @@
 			  send_message_ptr,
 			  tcpipv6_tran_rr_request->response_size,
 			  MSG_EOF,
-			  &peeraddr_in,
+			  (struct sockaddr *)&peeraddr_in,
 			  sizeof(struct sockaddr_in6))) == INVALID_SOCKET) {
       if (SOCKET_EINTR(bytes_sent)) {
 	/* the test timer has popped */
