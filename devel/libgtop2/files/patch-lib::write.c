--- lib/write.c.orig	Mon Apr 10 04:41:46 2006
+++ lib/write.c	Mon Apr 10 15:37:00 2006
@@ -22,7 +22,7 @@
 */
 
 #include <config.h>
-
+#include <errno.h>
 #include <glibtop/write.h>
 #include <glibtop/error.h>
 #include <glib/gi18n-lib.h>
@@ -42,15 +42,19 @@ glibtop_write_l (glibtop *server, size_t
 	fprintf (stderr, "LIBRARY: really writing %d bytes.\n", (int)size);
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
 		glibtop_error_io_r (server,
 				    ngettext("wrote %d byte",
 					     "wrote %d bytes", size),
 				    (int) size);
+	}
 }
