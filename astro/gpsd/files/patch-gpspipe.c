--- gpspipe.c.orig	Mon Jan 30 16:04:07 2006
+++ gpspipe.c	Mon Jan 30 16:04:56 2006
@@ -26,6 +26,7 @@
 
 #include <errno.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <unistd.h>
 #include <string.h>
