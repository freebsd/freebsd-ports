--- lib/read.c.orig	Mon Apr 11 03:25:32 2005
+++ lib/read.c	Mon Apr 11 03:27:06 2005
@@ -22,6 +22,7 @@
 */
 
 #include <config.h>
+#include <errno.h>
 #include <glibtop/read.h>
 #include <glibtop/error.h>
 #include "libgtop-i18n.h"
@@ -56,14 +57,18 @@
 	fprintf (stderr, "LIBRARY: really reading %d bytes.\n", size);
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
 				size);
+		}
 	}
 }
