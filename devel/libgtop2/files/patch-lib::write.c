--- lib/write.c.orig	Mon Sep  8 23:05:01 2003
+++ lib/write.c	Tue Sep  9 10:04:37 2003
@@ -21,6 +21,7 @@
    Boston, MA 02111-1307, USA.
 */
 
+#include <errno.h>
 #include <glibtop/write.h>
 
 /* Writes some data to server. */
@@ -38,12 +39,16 @@
 	fprintf (stderr, "LIBRARY: really writing %d bytes.\n", size);
 #endif
 
+retry:
 	if (server->socket) {
 		ret = send (server->socket, buf, size, 0);
 	} else {
 		ret = write (server->output [1], buf, size);
 	}
 
-	if (ret < 0)
+	if (ret < 0) {
+		if (errno == EINTR)
+			goto retry;
 		glibtop_error_io_r (server, _("write %d bytes"), size);
+	}
 }
