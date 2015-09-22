Obtained from:	https://github.com/facebook/rocksdb/commit/90415cfebe90bda845b9ee3e5a00e86d4f80e02e

--- util/sst_dump_tool.cc.orig	2015-08-31 18:23:39 UTC
+++ util/sst_dump_tool.cc
@@ -12,6 +12,7 @@
 #endif
 
 #include <inttypes.h>
+#include "port/port.h"
 
 namespace rocksdb {
 
@@ -164,7 +165,7 @@ int SstFileReader::ShowAllCompressionSiz
   compress_type.insert(
       std::make_pair(CompressionType::kLZ4HCCompression, "kLZ4HCCompression"));
 
-  fprintf(stdout, "Block Size: %lu\n", block_size);
+  fprintf(stdout, "Block Size: %" ROCKSDB_PRIszt "\n", block_size);
 
   for (CompressionType i = CompressionType::kNoCompression;
        i != CompressionType::kLZ4HCCompression; i = CompressionType(i + 1)) {
