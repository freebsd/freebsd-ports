--- subprojects/d2tk/src/base_pty.c.orig	1970-01-01 00:00:00 UTC
+++ subprojects/d2tk/src/base_pty.c
@@ -9,14 +9,26 @@
 #include <string.h>
 #include <fcntl.h>
 #include <vterm.h>
+#ifdef __FreeBSD__
+#include <libutil.h>
+#include <sys/ioctl.h>
+#include <sys/_termios.h>
+#else
 #include <pty.h>
-#include <utmp.h>
+#endif
+//#include <utmp.h>
 #include <sched.h>
 #include <limits.h>
 #include <sys/wait.h>
 #include <sys/mman.h>
 #include <pthread.h>
 #include <stdatomic.h>
+
+#ifdef __FreeBSD__
+extern char **environ;
+
+#define execvpe(a, b, c) execvp(a, b)
+#endif
 
 #include "base_internal.h"
 
