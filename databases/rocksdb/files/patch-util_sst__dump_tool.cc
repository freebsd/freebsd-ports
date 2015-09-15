--- util/sst_dump_tool.cc.orig	2015-08-31 18:23:39 UTC
+++ util/sst_dump_tool.cc
@@ -164,7 +164,7 @@ int SstFileReader::ShowAllCompressionSiz
   compress_type.insert(
       std::make_pair(CompressionType::kLZ4HCCompression, "kLZ4HCCompression"));
 
-  fprintf(stdout, "Block Size: %lu\n", block_size);
+  fprintf(stdout, "Block Size: %zu\n", block_size);
 
   for (CompressionType i = CompressionType::kNoCompression;
        i != CompressionType::kLZ4HCCompression; i = CompressionType(i + 1)) {
