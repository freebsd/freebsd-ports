--- modules/pty-open.c.orig	Sun Apr  4 12:58:08 2004
+++ modules/pty-open.c	Sun Apr  4 12:59:30 2004
@@ -613,6 +613,10 @@
 	if ((fd == -1) && (errno == ENOENT)) {
 		fd = open("/dev/ptc", O_RDWR | O_NOCTTY); /* AIX */
 	}
+
+	if ((fd == -1) && (errno == ENOENT)) {
+		fd = posix_openpt(O_RDWR);
+	}
 #endif
 	/* Set it to blocking. */
 	flags = fcntl(fd, F_GETFL);
