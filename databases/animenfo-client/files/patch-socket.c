--- socket.c.orig	Mon Aug 19 07:04:02 2002
+++ socket.c	Sun Nov  5 09:40:00 2006
@@ -5,6 +5,8 @@
 #include <sys/socket.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/time.h>
+#include <string.h>
 
 #include "socket.h"
 #include "definition.h"
