--- src/backend/distributed/worker/worker_sql_task_protocol.c.orig	2018-12-15 09:35:56 UTC
+++ src/backend/distributed/worker/worker_sql_task_protocol.c
@@ -12,6 +12,7 @@
 #include "postgres.h"
 #include "funcapi.h"
 #include "pgstat.h"
+#include <sys/stat.h>
 
 #include "distributed/multi_copy.h"
 #include "distributed/multi_executor.h"
