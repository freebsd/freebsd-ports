--- main/streams/xp_socket.c	2009/09/04 07:59:48	288034
+++ main/streams/xp_socket.c	2009/09/23 10:25:54	288604
@@ -289,7 +289,7 @@
 				if (sock->socket == -1) {
 					alive = 0;
 				} else if (php_pollfd_for(sock->socket, PHP_POLLREADABLE|POLLPRI, &tv) > 0) {
-					if (recv(sock->socket, &buf, sizeof(buf), MSG_PEEK) != SOCK_CONN_ERR && php_socket_errno() != EWOULDBLOCK) {
+					if (0 >= recv(sock->socket, &buf, sizeof(buf), MSG_PEEK) && php_socket_errno() != EWOULDBLOCK) {
 						alive = 0;
 					}
 				}
