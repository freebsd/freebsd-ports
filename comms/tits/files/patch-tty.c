
$FreeBSD$

--- tty.c	2001/04/18 14:43:52	1.1
+++ tty.c	2001/04/18 14:45:57
@@ -32,6 +32,7 @@
 #include <sys/types.h>
 #include <sys/filio.h>
 #include <sys/ioctl.h>
+#include <sys/stat.h>
 #include <sys/types.h>
 
 #include <ctype.h>
@@ -216,8 +217,7 @@
 	 * If this is *not* a pseudo tty, ensure DTR is asserted.
 	 * Note: This relies on TIOCGFLAGS returning ENOTTY for pty(4)'s.
 	 */
-	if (ioctl(cc->cc_fd, TIOCGFLAGS, &flags) == 0 && errno == ENOTTY &&
-	    ioctl(cc->cc_fd, TIOCSDTR, 0) < 0) {
+	if (ioctl(cc->cc_fd, TIOCSDTR, 0) < 0 && errno != ENOTTY) {
 		(void) close(cc->cc_fd);
 		(void) free(tc->tc_to.to_device);
 		(void) free(tc);
