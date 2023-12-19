--- daemon/loader.c.orig	2023-12-18 22:30:22 UTC
+++ daemon/loader.c
@@ -30,10 +30,18 @@
 
 #include <unistd.h>
 #include <fcntl.h>
-#include <pty.h>                /* forkpty() */
+#if !defined(__FreeBSD__)
+#  include <pty.h>                /* forkpty() */
+#else
+#  include <sys/types.h>
+#  include <sys/ioctl.h>
+#  include <termios.h>
+#  include <libutil.h>
+#endif
 #include <sys/wait.h>
 #include <sys/time.h>
 #include <sys/resource.h>
+#include <signal.h>
 
 #include "loader.h"
 #include "../proxies/conf_proxy.h"
