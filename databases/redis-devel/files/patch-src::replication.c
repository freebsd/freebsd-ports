--- src/replication.c.orig	2012-09-19 10:46:28.000000000 +0400
+++ src/replication.c	2012-09-19 10:47:01.000000000 +0400
@@ -1,5 +1,7 @@
 #include "redis.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/time.h>
 #include <unistd.h>
 #include <fcntl.h>
