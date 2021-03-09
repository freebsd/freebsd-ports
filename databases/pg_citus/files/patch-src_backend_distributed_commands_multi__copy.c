--- src/backend/distributed/commands/multi_copy.c.orig	2021-03-09 08:26:53 UTC
+++ src/backend/distributed/commands/multi_copy.c
@@ -53,6 +53,7 @@
 
 #include <arpa/inet.h> /* for htons */
 #include <netinet/in.h> /* for htons */
+#include <sys/stat.h>
 #include <string.h>
 
 #include "distributed/pg_version_constants.h"
