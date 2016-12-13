Obtained from:	https://github.com/facebook/rocksdb/commit/85bd8f518b55782f2fada586eabc953df15478e1

--- utilities/persistent_cache/hash_table_bench.cc.orig	2016-12-09 20:59:51 UTC
+++ utilities/persistent_cache/hash_table_bench.cc
@@ -272,9 +272,9 @@ class GranularLockImpl : public HashTabl
 // main
 //
 int main(int argc, char** argv) {
-  google::SetUsageMessage(std::string("\nUSAGE:\n") + std::string(argv[0]) +
+  GFLAGS::SetUsageMessage(std::string("\nUSAGE:\n") + std::string(argv[0]) +
                           " [OPTIONS]...");
-  google::ParseCommandLineFlags(&argc, &argv, false);
+  GFLAGS::ParseCommandLineFlags(&argc, &argv, false);
 
   //
   // Micro benchmark unordered_map
