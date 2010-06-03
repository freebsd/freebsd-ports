--- mysqlsniffer.c.ori	2006-08-18 16:52:52.000000000 +0200
+++ mysqlsniffer.c	2010-05-26 14:01:24.000000000 +0200
@@ -31,6 +31,7 @@
 #include <getopt.h>
 #include <signal.h>
 #include <sys/socket.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include "user_defines.h"
