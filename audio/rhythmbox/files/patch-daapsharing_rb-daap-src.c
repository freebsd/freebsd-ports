--- daapsharing/rb-daap-src.c.orig	Sun Oct 16 05:50:21 2005
+++ daapsharing/rb-daap-src.c	Mon Oct 17 10:30:20 2005
@@ -34,6 +34,7 @@
 #include <sys/ioctl.h>
 #include <netdb.h>
 #include <unistd.h>
+#include <signal.h>
 
 #include <libgnome/gnome-i18n.h>
 #include <gst/gst.h>
@@ -580,7 +581,15 @@ gst_tcp_socket_write (int socket, const 
 	size_t bytes_written = 0;
 
 	while (bytes_written < count) {
-		ssize_t wrote = send (socket, buf + bytes_written, count - bytes_written, MSG_NOSIGNAL);
+		ssize_t wrote;
+#ifdef MSG_NOSIGNAL
+		wrote = send (socket, buf + bytes_written, count - bytes_written, MSG_NOSIGNAL);
+#else
+		signal (SIGPIPE, SIG_IGN);
+		wrote = send (socket, buf + bytes_written, count - bytes_written, 0);
+		signal (SIGPIPE, SIG_DFL);
+#endif
+
 
 		if (wrote <= 0) {
 			return bytes_written;
