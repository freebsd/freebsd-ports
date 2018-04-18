--- src/auth/pool_hba.c.orig	2018-04-11 05:37:54 UTC
+++ src/auth/pool_hba.c
@@ -29,6 +29,8 @@
 #include <string.h>
 #include <errno.h>
 #include <netdb.h>
+#include <arpa/inet.h>
+#include <netinet/in.h>
 
 #include "pool.h"
 #include "auth/pool_hba.h"
