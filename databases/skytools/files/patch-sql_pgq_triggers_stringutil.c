--- sql/pgq/triggers/stringutil.c.orig	2019-08-05 04:48:30 UTC
+++ sql/pgq/triggers/stringutil.c
@@ -19,7 +19,11 @@
 #include <postgres.h>
 #include <lib/stringinfo.h>
 #include <mb/pg_wchar.h>
+#if PG_VERSION_NUM < 110000
 #include <parser/keywords.h>
+#else
+#include <common/keywords.h>
+#endif
 #include <utils/memutils.h>
 
 #include "stringutil.h"
