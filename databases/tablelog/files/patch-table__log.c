--- table_log.c.orig	2007-05-16 23:14:04 UTC
+++ table_log.c
@@ -22,6 +22,8 @@
 #include "utils/formatting.h"
 #include "utils/builtins.h"
 #include <utils/lsyscache.h>
+#include <utils/rel.h>
+#include <utils/timestamp.h>
 #include <funcapi.h>
 
 /* for PostgreSQL >= 8.2.x */
