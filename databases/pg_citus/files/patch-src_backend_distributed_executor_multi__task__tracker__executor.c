--- src/backend/distributed/executor/multi_task_tracker_executor.c.orig	2016-03-23 23:36:42 UTC
+++ src/backend/distributed/executor/multi_task_tracker_executor.c
@@ -20,6 +20,7 @@
 #include "postgres.h"
 #include "miscadmin.h"
 
+#include <sys/stat.h>
 #include <unistd.h>
 
 #include "commands/dbcommands.h"
