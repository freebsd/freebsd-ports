Patch can be removed in next release
Upstream fix: 
https://github.com/phpredis/phpredis/pull/1800

--- redis.c.orig	2020-07-03 06:16:52 UTC
+++ redis.c
@@ -30,7 +30,7 @@
 #include <standard/php_random.h>
 #include <zend_exceptions.h>
 #include <ext/standard/info.h>
-
+#include <ext/hash/php_hash.h>
 
 #ifdef PHP_SESSION
 #include <ext/session/php_session.h>
