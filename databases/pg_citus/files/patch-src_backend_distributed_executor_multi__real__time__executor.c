--- src/backend/distributed/executor/multi_real_time_executor.c.orig	2018-12-13 13:22:48 UTC
+++ src/backend/distributed/executor/multi_real_time_executor.c
@@ -21,6 +21,7 @@
 
 #include <sys/stat.h>
 #include <unistd.h>
+#include <sys/stat.h>
 
 #include "access/xact.h"
 #include "commands/dbcommands.h"
