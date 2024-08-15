--- src/lib/usefulstuff.c.orig	2024-08-03 13:55:22 UTC
+++ src/lib/usefulstuff.c
@@ -41,7 +41,11 @@
 #include "usefulstuff.h"
 #include "log.h"

+#if PHP_VERSION_ID <= 80300
 #include "ext/standard/php_lcg.h"
+#else
+#include "ext/random/php_random.h"
+#endif
 #include "ext/standard/flock_compat.h"
 #include "main/php_ini.h"

