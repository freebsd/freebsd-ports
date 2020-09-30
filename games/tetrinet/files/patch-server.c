--- server.c.orig	2003-09-07 16:29:29 UTC
+++ server.c
@@ -839,7 +839,7 @@ static void check_sockets()
 
     if (listen_sock >= 0 && FD_ISSET(listen_sock, &fds)) {
 	struct sockaddr_in sin;
-	int len = sizeof(sin);
+	socklen_t len = sizeof(sin);
 	fd = accept(listen_sock, (struct sockaddr *)&sin, &len);
 	if (fd >= 0) {
 	    for (i = 0; i < 6 && player_socks[i] != -1; i++)
@@ -857,7 +857,7 @@ static void check_sockets()
 #ifdef HAVE_IPV6
     if (listen_sock6 >= 0 && FD_ISSET(listen_sock6, &fds)) {
 	struct sockaddr_in6 sin6;
-	int len = sizeof(sin6);
+	socklen_t len = sizeof(sin6);
 	fd = accept(listen_sock6, (struct sockaddr *)&sin6, &len);
 	if (fd >= 0) {
 	    for (i = 0; i < 6 && player_socks[i] != -1; i++)
