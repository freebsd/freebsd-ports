--- src/helper/helper-socket.c.orig	Tue Apr 12 20:10:13 2005
+++ src/helper/helper-socket.c	Thu Dec 29 23:05:18 2005
@@ -25,6 +25,8 @@
 
 #include <glib.h>
 
+#include <sys/types.h>
+#include <sys/time.h>
 #include <netinet/in.h>
 #include <string.h>
 #include <sys/types.h>
