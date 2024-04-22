--- sim_sock.c.orig	2024-03-21 04:42:41 UTC
+++ sim_sock.c
@@ -1412,7 +1412,7 @@ void sim_close_sock (SOCKET sock)
 
 void sim_close_sock (SOCKET sock)
 {
-shutdown(sock, SD_BOTH);
+shutdown(sock, SHUT_RDWR);
 closesocket (sock);
 }
 
