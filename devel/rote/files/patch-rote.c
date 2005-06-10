--- rote.c.orig	Wed Oct  6 19:18:49 2004
+++ rote.c	Fri Jun 10 11:57:27 2005
@@ -21,8 +21,11 @@
 
 #include "rote.h"
 #include "roteprivate.h"
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
 #include <stdlib.h>
-#include <pty.h>
 #include <stdio.h>
 #include <string.h>
 
