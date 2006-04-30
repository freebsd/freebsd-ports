--- lib/read.c.orig	Mon Apr 10 04:41:46 2006
+++ lib/read.c	Mon Apr 10 15:12:31 2006
@@ -22,6 +22,7 @@
 */
 
 #include <config.h>
+#include <errno.h>
 #include <glibtop/read.h>
 #include <glibtop/error.h>
 #include <glib/gi18n-lib.h>
@@ -56,14 +57,18 @@ glibtop_read_l (glibtop *server, size_t 
 	fprintf (stderr, "LIBRARY: really reading %d bytes.\n", (int)size);
 #endif
 
+retry:
 	if (server->socket) {
 		do_read (server->socket, buf, size);
 	} else {
-		if(read (server->input [0], buf, size) < 0)
+		if(read (server->input [0], buf, size) < 0) {
+			if (errno == EINTR)
+				goto retry;
 			glibtop_error_io_r (
 				server,
 				ngettext ("read %d byte",
 					  "read %d bytes", size),
 				(int)size);
+		}
 	}
 }
