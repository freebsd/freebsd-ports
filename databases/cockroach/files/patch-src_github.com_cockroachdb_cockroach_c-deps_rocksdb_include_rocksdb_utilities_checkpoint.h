--- src/github.com/cockroachdb/cockroach/c-deps/rocksdb/include/rocksdb/utilities/checkpoint.h.orig	2020-06-29 21:13:41 UTC
+++ src/github.com/cockroachdb/cockroach/c-deps/rocksdb/include/rocksdb/utilities/checkpoint.h
@@ -9,6 +9,7 @@
 #ifndef ROCKSDB_LITE
 
 #include <string>
+#include <cstdint>
 #include "rocksdb/status.h"
 
 namespace rocksdb {
