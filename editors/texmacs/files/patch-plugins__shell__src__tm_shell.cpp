--- plugins/shell/src/tm_shell.cpp.orig	2010-09-27 04:36:19.000000000 -0700
+++ plugins/shell/src/tm_shell.cpp	2010-09-27 04:38:09.000000000 -0700
@@ -19,14 +19,10 @@
 #include <unistd.h>
 #include <sys/time.h>
 #include <sys/wait.h>
+#include <sys/types.h>
+#include <sys/ioctl.h>
 #include <termios.h>
-
-#if HAVE_PTY_H
-#include <pty.h>
-#endif
-#if HAVE_UTIL_H
-#include <util.h>
-#endif
+#include <libutil.h>
 
 using namespace std;
 
