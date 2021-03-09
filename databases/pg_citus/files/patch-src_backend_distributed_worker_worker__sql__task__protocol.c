--- src/backend/distributed/worker/worker_sql_task_protocol.c.orig	2021-03-03 14:26:26 UTC
+++ src/backend/distributed/worker/worker_sql_task_protocol.c
@@ -12,6 +12,7 @@
 #include "postgres.h"
 #include "funcapi.h"
 #include "pgstat.h"
+#include <sys/stat.h>
 
 #include "distributed/commands/multi_copy.h"
 #include "distributed/multi_executor.h"
