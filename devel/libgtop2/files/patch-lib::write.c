--- lib/write.c.orig	Mon Apr 11 03:28:12 2005
+++ lib/write.c	Mon Apr 11 03:29:00 2005
@@ -22,7 +22,7 @@
 */
 
 #include <config.h>
-
+#include <errno.h>
 #include <glibtop/write.h>
 #include <glibtop/error.h>
 #include "libgtop-i18n.h"
@@ -42,12 +42,16 @@
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
 		glibtop_error_io_r (server, ngettext ("wrote %d byte", "wrote %d bytes", size), size);
+	}
 }
