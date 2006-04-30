--- src/daemon/io.c.orig	Mon Dec 12 05:09:38 2005
+++ src/daemon/io.c	Wed Dec 14 18:58:01 2005
@@ -21,6 +21,7 @@
    Boston, MA 02111-1307, USA.
 */
 
+#include <errno.h>
 #include <config.h>
 #include "daemon.h"
 #include <glibtop/error.h>
@@ -37,9 +38,13 @@ do_output (int s, glibtop_response *resp
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
@@ -50,9 +55,13 @@ do_output (int s, glibtop_response *resp
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
@@ -68,6 +77,7 @@ do_read (int s, void *ptr, size_t total_
 	size_t already_read = 0, remaining = total_size;
 
 	while (already_read < total_size) {
+retry:
 		if (s)
 			nread = recv (s, ptr, remaining, 0);
 		else
@@ -79,6 +89,8 @@ do_read (int s, void *ptr, size_t total_
 		}
 
 		if (nread <= 0) {
+			if (errno == EINTR)
+				goto retry;
 			glibtop_warn_io ("recv");
 			return 0;
 		}
