--- ./wrapper.c.orig	2010-07-28 13:03:43.000000000 -0400
+++ ./wrapper.c	2010-08-16 21:56:14.250979872 -0400
@@ -131,7 +131,7 @@
 {
 	ssize_t nr;
 	while (1) {
-		nr = read(fd, buf, len);
+		nr = read(fd, buf, MIN(INT_MAX, len));
 		if ((nr < 0) && (errno == EAGAIN || errno == EINTR))
 			continue;
 		return nr;
@@ -147,7 +147,7 @@
 {
 	ssize_t nr;
 	while (1) {
-		nr = write(fd, buf, len);
+		nr = write(fd, buf, MIN(INT_MAX, len));
 		if ((nr < 0) && (errno == EAGAIN || errno == EINTR))
 			continue;
 		return nr;
