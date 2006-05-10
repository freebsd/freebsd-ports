--- sapi/cgi/fastcgi.c.orig	Wed May 10 08:04:51 2006
+++ sapi/cgi/fastcgi.c	Wed May 10 08:07:04 2006
@@ -633,6 +633,9 @@
 #ifdef _WIN32
 	HANDLE pipe;
 	OVERLAPPED ov;
+#else
+	sa_t sa;
+	socklen_t len = sizeof(sa);
 #endif
 	fcgi_finish_request(req);
 
@@ -669,9 +672,6 @@
 				}
 				FCGI_UNLOCK(req->listen_socket);
 #else
-				sa_t sa;
-				socklen_t len = sizeof(sa);
-
 				FCGI_LOCK(req->listen_socket);
 				req->fd = accept(req->listen_socket, (struct sockaddr *)&sa, &len);
 				FCGI_UNLOCK(req->listen_socket);
