--- pool_hba.c.orig	2018-02-13 05:20:52 UTC
+++ pool_hba.c
@@ -29,6 +29,7 @@
 #include <string.h>
 #include <errno.h>
 #include <netdb.h>
+#include <netinet/in.h>
 
 #include "pool.h"
 #include "pool_path.h"
