--- cddb-slave2/tcp.c.orig	Mon Sep 20 14:52:50 2004
+++ cddb-slave2/tcp.c	Sat Mar 12 03:30:52 2005
@@ -265,7 +265,7 @@ gnet_tcp_socket_new_async (const GInetAd
 		continue;
 
 	      sa_in6->sin6_scope_id = ifindex;
-	      con = connect (s->sockfd, (struct sockaddr *)&sa6, sizeof(s->sa));
+	      con = connect (s->sockfd, (struct sockaddr *)&sa6, sizeof(sa6));
 	      if (con == 0 || errno == EINPROGRESS)
 				break;
 
@@ -283,7 +283,7 @@ gnet_tcp_socket_new_async (const GInetAd
       memcpy(&sa, &addr->sa, sizeof(sa));
       sa_in = (struct sockaddr_in *) &sa;
       sa_in->sin_family = AF_INET;
-      con = connect(s->sockfd, &sa, sizeof(s->sa));
+      con = connect(s->sockfd, &sa, sizeof(sa));
     }
 
   /* Connect (but non-blocking!) */
