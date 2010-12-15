--- plugins/r/src/tm_r.c.orig	2010-11-24 12:52:55.000000000 -0800
+++ plugins/r/src/tm_r.c	2010-12-12 11:31:52.000000000 -0800
@@ -10,20 +10,22 @@
 ******************************************************************************/
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/select.h>
+#ifdef __FreeBSD__
+#include <libutil.h>
+#else
 #if HAVE_PTY_H
 #include <pty.h>
 #endif
+#endif
 
-#include <utmp.h>
 #include <unistd.h>
 #include <termios.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <string.h>
-#include <util.h>
 
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/time.h>
