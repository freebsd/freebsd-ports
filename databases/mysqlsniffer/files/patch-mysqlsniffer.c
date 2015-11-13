--- mysqlsniffer.c.orig	2006-08-18 14:52:52 UTC
+++ mysqlsniffer.c
@@ -31,6 +31,7 @@
 #include <getopt.h>
 #include <signal.h>
 #include <sys/socket.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include "user_defines.h"
