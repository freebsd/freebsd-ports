--- echolinux/control.c.orig	Mon Feb  2 22:29:46 2004
+++ echolinux/control.c	Fri Jul  2 00:58:38 2004
@@ -24,7 +24,8 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <errno.h>
-#include <wait.h>
+#include <sys/types.h>
+#include <sys/wait.h>
 #include <signal.h>
 #include <string.h>
 #include <sys/time.h>
