--- src/shellout.c.orig	Mon Mar 10 09:10:10 2003
+++ src/shellout.c	Tue Apr 15 12:46:00 2003
@@ -27,7 +27,7 @@
 #include <string.h>
 #include <termios.h>
 #include <unistd.h>
-#include <pty.h>
+/* #include <pty.h> */
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/wait.h>
