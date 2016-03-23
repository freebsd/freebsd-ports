--- plugins/r/src/tm_r.c.orig	2014-03-03 11:44:12 UTC
+++ plugins/r/src/tm_r.c
@@ -11,19 +11,22 @@
 #define TEXMACS_R_VERSION "0.15"
 
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
 
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/time.h>
