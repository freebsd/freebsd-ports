--- ./msgpack_pack.h.orig	2011-07-27 09:50:36.000000000 +0400
+++ ./msgpack_pack.h	2012-05-28 15:06:00.764503031 +0400
@@ -2,7 +2,13 @@
 #ifndef MSGPACK_PACK_H
 #define MSGPACK_PACK_H
 
-#include "ext/standard/php_smart_str.h"
+#include "ext/standard/php_var.h"
+
+#if PHP_API_VERSION < 20100412
+#define msgpack_serialize_data_t HashTable
+#else
+typedef HashTable* msgpack_serialize_data_t;
+#endif
 
 enum msgpack_serialize_type
 {
