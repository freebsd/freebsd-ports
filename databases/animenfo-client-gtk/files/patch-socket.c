--- src/socket.c.orig	Fri Aug 16 03:54:46 2002
+++ src/socket.c	Sun May 23 10:28:29 2004
@@ -5,6 +5,7 @@
 #include <sys/socket.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/time.h>
 
 #include "socket.h"
 #include "definition.h"
