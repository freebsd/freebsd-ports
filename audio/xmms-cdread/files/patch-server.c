--- server.c.orig	Fri Jul 20 00:26:42 2001
+++ server.c	Sun Mar 23 16:35:33 2003
@@ -282,7 +282,7 @@
 		if (r < 0) {
 			req->rest[0] = 0;
 			if (errno == EAGAIN) {
-				errno = ETIME;
+				errno = ETIMEDOUT;
 				if (++rtr < READ_TIMEOUT) {
 					xmms_usleep(READ_USEC);
 					continue;
@@ -312,7 +312,7 @@
 		gint w = write(sock, p, strlen(p));
 		if (w < 0) {
 			if (errno == EAGAIN) {
-				errno = ETIME;
+				errno = ETIMEDOUT;
 				if (++rtr < READ_TIMEOUT) {
 					xmms_usleep(READ_USEC);
 					continue;
