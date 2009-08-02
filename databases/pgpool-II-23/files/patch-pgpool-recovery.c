--- sql/pgpool-recovery/pgpool-recovery.c.orig     2009-07-23 17:30:52.000000000 +0000
+++ sql/pgpool-recovery/pgpool-recovery.c  2009-07-23 17:31:34.000000000 +0000
@@ -23,6 +23,7 @@
 #include "miscadmin.h"
 #include "executor/spi.h"
 #include "funcapi.h"
+#include "utils/builtins.h"   /* PostgreSQL 8.4 needs this for textout */

 #define REMOTE_START_FILE "pgpool_remote_start"

