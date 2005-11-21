--- ttt3d/main.c.orig	Mon Nov 21 14:25:08 2005
+++ ttt3d/main.c	Mon Nov 21 14:25:39 2005
@@ -26,6 +26,7 @@
 
 #include <stdlib.h>
 #include <stdio.h>
+#include <sys/time.h>
 #ifdef HAVE_WINSOCK_H
 # include <winsock.h>
 #endif
