--- src/shellout.c.orig	Fri May 28 23:52:03 2004
+++ src/shellout.c	Tue Mar  8 16:56:58 2005
@@ -27,12 +27,15 @@
 #include <string.h>
 #include <termios.h>
 #include <unistd.h>
-#include <pty.h>
 #include <errno.h>
 #include <sys/types.h>
+#include <sys/ioctl.h>
 #include <sys/wait.h>
 #include <sys/time.h>
+#include <sys/select.h>
 #include <signal.h>
+#include <termios.h>
+#include <libutil.h>
 #include "mba/msgno.h"
 #include "mba/text.h"
 #include "mba/shellout.h"
