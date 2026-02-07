--- unix/unix_console.c.orig	Mon Jul 24 21:31:05 2006
+++ unix/unix_console.c	Mon Jul 24 21:32:15 2006
@@ -25,6 +25,7 @@
 #include "unix_local.h"
 #include <unistd.h>
 #include <fcntl.h>
+#include <sys/time.h>
 
 qBool	stdin_active = qTrue;
 
