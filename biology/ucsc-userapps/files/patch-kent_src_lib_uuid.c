--- kent/src/lib/uuid.c.orig	2021-04-14 11:22:38 UTC
+++ kent/src/lib/uuid.c
@@ -6,7 +6,7 @@
  * If you use this file you need to add -luuid to your link line. */
 
 #include "common.h"
-#include "uuid.h"
+#include "my_uuid.h"
 
 char *makeUuidString(char buf[37])
 /* Generate a random uuid and put it in the usual hex-plus-dashes form */
