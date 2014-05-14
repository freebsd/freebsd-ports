--- src/fgrun_pty.cxx.orig	2014-05-12 04:35:04.000000000 +0800
+++ src/fgrun_pty.cxx	2014-05-12 04:35:29.000000000 +0800
@@ -40,6 +40,11 @@
 #include <fcntl.h>	// O_RDWR
 #endif
 
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
+
 #include <stdlib.h> //needed on some linux systems for grantpt()
 #include <string.h> //strcpy is not necessarily already included
 /**
