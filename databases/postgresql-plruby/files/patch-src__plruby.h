--- ./src/plruby.h.orig	2012-12-23 14:51:17.000000000 +0100
+++ ./src/plruby.h	2013-11-19 15:29:16.000000000 +0100
@@ -7,6 +7,7 @@
 #include "executor/executor.h"
 #include "commands/trigger.h"
 #include "utils/elog.h"
+#include "utils/rel.h"
 #include "utils/builtins.h"
 #include "fmgr.h"
 #include "access/heapam.h"
@@ -35,6 +36,10 @@
 #include "utils/memutils.h"
 #endif
 
+#if PG_PL_VERSION >= 93
+#include "access/htup_details.h"
+#endif
+
 #include "package.h"
 
 #include <ruby.h>
