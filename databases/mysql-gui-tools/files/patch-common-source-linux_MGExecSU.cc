--- common/source/linux/MGExecSU.cc.orig	2008-03-07 01:50:54.000000000 +0100
+++ common/source/linux/MGExecSU.cc	2008-03-07 01:52:50.000000000 +0100
@@ -5,10 +5,14 @@
 #include "myg_gtkutils.h"
 #include "mygpriv.h"
 #include <sys/signal.h>
+#include <sys/types.h>
+#include <sys/ioctl.h>
 #include <sys/wait.h>
+#include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
-#include <pty.h>
+#include <termios.h>
+#include <libutil.h>
 #include <fcntl.h>
 
 
