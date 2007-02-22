--- plugins/daap/rb-daap-src.c.orig	Fri Jan 27 21:11:13 2006
+++ plugins/daap/rb-daap-src.c	Thu Feb  2 02:07:48 2006
@@ -34,6 +34,7 @@
 #include <sys/ioctl.h>
 #include <netdb.h>
 #include <unistd.h>
+#include <signal.h>
 #include <ctype.h>
 
 #include <libsoup/soup-headers.h>
@@ -435,7 +436,14 @@ rb_daap_src_write (RBDAAPSrc *src, const
 	size_t bytes_written = 0;
 
 	while (bytes_written < count) {
-		ssize_t wrote = send (src->sock_fd, buf + bytes_written, count - bytes_written, MSG_NOSIGNAL);
+		ssize_t wrote;
+#ifdef MSG_NOSIGNAL
+		wrote = send (src->sock_fd, buf + bytes_written, count - bytes_written, MSG_NOSIGNAL);
+#else
+		signal (SIGPIPE, SIG_IGN);
+		wrote = send (src->sock_fd, buf + bytes_written, count - bytes_written, 0);
+		signal (SIGPIPE, SIG_DFL);
+#endif
 
 		if (wrote < 0) {
 			GST_WARNING ("error while writing: %s", g_strerror (errno));
