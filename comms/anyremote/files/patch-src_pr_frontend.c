--- src/pr_frontend.c.orig	2009-04-10 14:17:39.000000000 +1000
+++ src/pr_frontend.c	2009-04-10 14:17:53.000000000 +1000
@@ -25,6 +25,8 @@
 #include <string.h>
 #include <sys/socket.h>
 #include <unistd.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 
 #include "common.h"
 #include "utils.h"
