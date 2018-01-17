--- src/backend/distributed/executor/multi_real_time_executor.c.orig	2018-01-17 22:05:28 UTC
+++ src/backend/distributed/executor/multi_real_time_executor.c
@@ -20,6 +20,7 @@
 #include "miscadmin.h"
 
 #include <unistd.h>
+#include <sys/stat.h>
 
 #include "access/xact.h"
 #include "commands/dbcommands.h"
