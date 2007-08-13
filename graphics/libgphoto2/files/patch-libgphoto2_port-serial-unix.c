--- libgphoto2_port/serial/unix.c.orig	Fri Jul 27 02:36:13 2007
+++ libgphoto2_port/serial/unix.c	Mon Aug 13 17:26:43 2007
@@ -43,6 +43,7 @@
 #endif
 #include <string.h>
 #include <signal.h>
+#include <sys/select.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #ifdef HAVE_SYS_TIME_H
@@ -348,11 +349,11 @@
 		/* resmgr has its own API, which calls to a server and
 		 * communicates over UNIX domain sockets.
 		 */
-		fd = rsm_open_device(path, O_RDONLY | O_NDELAY);
+		fd = rsm_open_device(path, O_RDONLY | O_NONBLOCK);
 		/* fall through to standard open if this failed */
 #endif
 		if (fd == -1)
-			fd = open (path, O_RDONLY | O_NDELAY);
+			fd = open (path, O_RDONLY | O_NONBLOCK);
 		if (fd < 0) {
 			gp_port_serial_unlock (NULL, path);
 			continue;
