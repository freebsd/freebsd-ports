--- pammodem/meas.c.orig	Tue Sep 19 17:44:23 2006
+++ pammodem/meas.c	Tue Sep 19 17:51:00 2006
@@ -32,6 +32,8 @@
 #ifdef HAVE_STROPTS_H
 #include <stropts.h>
 #endif
+#include <sys/param.h>
+#include <sys/types.h>
 #ifdef HAVE_SYS_CONF_H
 #include <sys/conf.h>
 #endif
@@ -45,12 +47,12 @@
 #include <sys/soundcard.h>
 #endif
 
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <poll.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <strings.h>
 #include <unistd.h>
 #include <signal.h>
