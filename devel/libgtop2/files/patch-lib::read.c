--- lib/read.c.orig	Fri May  7 07:09:24 1999
+++ lib/read.c	Tue Sep  9 10:02:54 2003
@@ -21,6 +21,7 @@
    Boston, MA 02111-1307, USA.
 */
 
+#include <errno.h>
 #include <glibtop/read.h>
 
 /* Reads some data from server. */
@@ -65,12 +66,16 @@
 	fprintf (stderr, "LIBRARY: really reading %d bytes.\n", size);
 #endif
 
+retry:
 	if (server->socket) {
 		do_read (server->socket, buf, size);
 	} else {
 		ret = read (server->input [0], buf, size);
 	}
 
-	if (ret < 0)
+	if (ret < 0) {
+		if (errno == EINTR)
+			goto retry;
 		glibtop_error_io_r (server, _("read %d bytes"), size);
+	}
 }
