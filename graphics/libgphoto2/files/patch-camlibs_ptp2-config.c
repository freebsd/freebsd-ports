--- camlibs/ptp2/config.c.orig	Tue Dec 12 18:43:53 2006
+++ camlibs/ptp2/config.c	Tue Dec 12 19:00:45 2006
@@ -24,6 +24,7 @@
 #include <string.h>
 #include <stdio.h>
 #include <time.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
