--- lib/read.c.orig	Mon Oct 20 11:19:41 2003
+++ lib/read.c	Fri Nov 14 14:37:00 2003
@@ -22,6 +22,7 @@
 */
 
 #include <config.h>
+#include <errno.h>
 #include <glibtop/read.h>
 #include <libgnome/gnome-i18n.h>
 
@@ -68,12 +69,16 @@
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
