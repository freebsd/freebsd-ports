--- third_party/snappy/src/snappy.h.orig	2019-12-12 12:45:20 UTC
+++ third_party/snappy/src/snappy.h
@@ -73,7 +73,7 @@ namespace snappy {
   // Original contents of *output are lost.
   //
   // REQUIRES: "input[]" is not an alias of "*output".
-  size_t Compress(const char* input, size_t input_length, string* output);
+  size_t Compress(const char* input, size_t input_length, std::string* output);
 
   // Decompresses "compressed[0,compressed_length-1]" to "*uncompressed".
   // Original contents of "*uncompressed" are lost.
@@ -82,7 +82,7 @@ namespace snappy {
   //
   // returns false if the message is corrupted and could not be decompressed
   bool Uncompress(const char* compressed, size_t compressed_length,
-                  string* uncompressed);
+                  std::string* uncompressed);
 
   // Decompresses "compressed" to "*uncompressed".
   //
