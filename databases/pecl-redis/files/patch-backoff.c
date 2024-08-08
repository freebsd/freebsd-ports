--- backoff.c.orig	2024-08-03 17:49:28 UTC
+++ backoff.c
@@ -1,9 +1,17 @@
 #include "common.h"
 
+#if PHP_VERSION_ID <= 80300
 #include <ext/standard/php_rand.h>
+#else
+#include <ext/random/php_random.h>
+#endif
 
 #if PHP_VERSION_ID >= 70100
+#if PHP_VERSION_ID <= 80300
 #include <ext/standard/php_mt_rand.h>
+#else
+#include <ext/random/php_random.h>
+#endif
 #else
 static zend_long php_mt_rand_range(zend_long min, zend_long max) {
     zend_long number = php_rand();
