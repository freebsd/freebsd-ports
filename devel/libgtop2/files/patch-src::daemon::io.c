--- src/daemon/io.c.orig	Mon Apr 11 03:30:12 2005
+++ src/daemon/io.c	Mon Apr 11 03:33:22 2005
@@ -21,6 +21,7 @@
    Boston, MA 02111-1307, USA.
 */
 
+#include <errno.h>
 #include "daemon.h"
 #include <glibtop/error.h>
 
@@ -36,9 +37,13 @@
 	resp->offset = offset;
 	resp->data_size = data_size;
 
+retry1:
 	if (s == 0) {
-		if (write (1, (const void *) resp, sizeof (glibtop_response)) < 0)
+		if (write (1, (const void *) resp, sizeof (glibtop_response)) < 0) {
+			if (errno == EINTR)
+				goto retry1;
 			glibtop_warn_io ("write");
+		}
 	} else {
 		if (send (s, (const void *) resp, sizeof (glibtop_response), 0) < 0)
 			glibtop_warn_io ("send");
@@ -49,9 +54,13 @@
 		fprintf (stderr, "Writing %d bytes of data.\n", resp->data_size);
 #endif
 
+retry2:
 		if (s == 0) {
-			if (write (1, data, resp->data_size) < 0)
+			if (write (1, data, resp->data_size) < 0) {
+				if (errno == EINTR)
+					goto retry2;
 				glibtop_warn_io ("write");
+			}
 		} else {
 			if (send (s, data, resp->data_size, 0) , 0)
 				glibtop_warn_io ("send");
@@ -67,6 +76,7 @@
 	size_t already_read = 0, remaining = total_size;
 
 	while (already_read < total_size) {
+retry:
 		if (s)
 			nread = recv (s, ptr, remaining, 0);
 		else
@@ -78,6 +88,8 @@
 		}
 
 		if (nread <= 0) {
+			if (errno == EINTR)
+				goto retry;
 			glibtop_warn_io ("recv");
 			return 0;
 		}
