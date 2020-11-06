--- src/tarantool_msgpack.c.orig	2020-06-29 22:41:13 UTC
+++ src/tarantool_msgpack.c
@@ -5,6 +5,10 @@
 
 #include "third_party/msgpuck.h"
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_FETCH()
+#endif
+
 #ifndef    HASH_KEY_NON_EXISTENT
 #define    HASH_KEY_NON_EXISTENT HASH_KEY_NON_EXISTANT
 #endif  /* HASH_KEY_NON_EXISTENT */
