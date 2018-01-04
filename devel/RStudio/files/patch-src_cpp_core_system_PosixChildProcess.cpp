--- src/cpp/core/system/PosixChildProcess.cpp.orig	2017-11-16 21:40:37 UTC
+++ src/cpp/core/system/PosixChildProcess.cpp
@@ -19,14 +19,18 @@
 #include <fcntl.h>
 #include <signal.h>
 #include <unistd.h>
+#include <termios.h>
 
 #ifdef __APPLE__
 #include <util.h>
 #include <sys/ttycom.h>
 #include <sys/ioctl.h>
 #else
-#include <pty.h>
-#include <asm/ioctls.h>
+//#include <pty.h>
+//#include <asm/ioctls.h>
+#include <sys/tty.h>
+#include <sys/ttycom.h>
+#include <libutil.h>
 #endif
 
 #include <sys/wait.h>
