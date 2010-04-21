--- wrapper.c.orig	2010-04-17 10:41:51.454820281 -0400
+++ wrapper.c	2010-04-17 11:00:32.542693956 -0400
@@ -117,7 +117,7 @@
 {
 	ssize_t nr;
 	while (1) {
-		nr = read(fd, buf, len);
+		nr = read(fd, buf, MIN(INT_MAX, len));
 		if ((nr < 0) && (errno == EAGAIN || errno == EINTR))
 			continue;
 		return nr;
@@ -133,7 +133,7 @@
 {
 	ssize_t nr;
 	while (1) {
-		nr = write(fd, buf, len);
+		nr = write(fd, buf, MIN(INT_MAX, len));
 		if ((nr < 0) && (errno == EAGAIN || errno == EINTR))
 			continue;
 		return nr;
