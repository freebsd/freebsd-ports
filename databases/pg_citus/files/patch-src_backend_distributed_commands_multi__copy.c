--- src/backend/distributed/commands/multi_copy.c.orig	2016-05-19 14:44:50 UTC
+++ src/backend/distributed/commands/multi_copy.c
@@ -52,6 +52,7 @@
 #include "plpgsql.h"
 
 #include <string.h>
+#include <netinet/in.h>
 
 #include "access/heapam.h"
 #include "access/htup_details.h"
