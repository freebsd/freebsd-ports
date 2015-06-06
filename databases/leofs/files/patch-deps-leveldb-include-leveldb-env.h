--- deps/leveldb/include/leveldb/env.h.orig	2015-06-06 06:41:04.463152255 +0000
+++ deps/leveldb/include/leveldb/env.h	2015-06-06 06:46:21.094442005 +0000
@@ -13,6 +13,8 @@
 #ifndef STORAGE_LEVELDB_INCLUDE_ENV_H_
 #define STORAGE_LEVELDB_INCLUDE_ENV_H_
 
+#include <pthread.h>
+
 #include <cstdarg>
 #include <string>
 #include <vector>
