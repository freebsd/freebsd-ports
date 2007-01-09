--- src/internals.h.orig	Fri Jan  5 06:33:06 2007
+++ src/internals.h	Fri Jan  5 23:27:32 2007
@@ -29,12 +29,13 @@
 #  include <unistd.h>
 #endif
 #include <netdb.h>
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
-#include <sys/types.h>
 #include <string.h>
 #include <stdarg.h>
 #include <signal.h>
