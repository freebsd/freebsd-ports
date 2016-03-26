--- src/backend/distributed/worker/worker_partition_protocol.c.orig	2016-03-23 23:36:42 UTC
+++ src/backend/distributed/worker/worker_partition_protocol.c
@@ -17,6 +17,7 @@
 #include "postgres.h"
 #include "funcapi.h"
 
+#include <netinet/in.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #ifdef HAVE_INTTYPES_H
