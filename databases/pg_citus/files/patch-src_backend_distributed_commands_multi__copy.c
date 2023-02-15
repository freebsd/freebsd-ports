--- src/backend/distributed/commands/multi_copy.c.orig	2023-02-03 08:13:35 UTC
+++ src/backend/distributed/commands/multi_copy.c
@@ -50,6 +50,7 @@
 
 #include <arpa/inet.h> /* for htons */
 #include <netinet/in.h> /* for htons */
+#include <sys/stat.h>
 #include <string.h>
 
 #include "distributed/pg_version_constants.h"
