--- library.c.orig	2024-08-03 17:50:52 UTC
+++ library.c
@@ -56,7 +56,11 @@
 #include <ext/json/php_json.h>
 #endif
 
+#if PHP_VERSION_ID <= 80300
 #include <ext/standard/php_rand.h>
+#else
+#include <ext/random/php_random.h>
+#endif
 #include <ext/hash/php_hash.h>
 
 #define UNSERIALIZE_NONE 0
