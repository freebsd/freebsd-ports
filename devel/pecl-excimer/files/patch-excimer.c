--- excimer.c.orig	2024-08-03 14:37:54 UTC
+++ excimer.c
@@ -23,7 +23,10 @@
 #include "zend_exceptions.h"
 #include "zend_interfaces.h"
 #include "ext/spl/spl_exceptions.h"
+#if PHP_VERSION_ID <= 80300
 #include "ext/standard/php_mt_rand.h"
+#include "ext/random/php_random.h"
+#endif
 #include "ext/standard/info.h"

 #if PHP_VERSION_ID < 70200
