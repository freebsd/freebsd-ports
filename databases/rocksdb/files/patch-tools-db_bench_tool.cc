--- tools/db_bench_tool.cc.orig	2018-11-12 19:57:32 UTC
+++ tools/db_bench_tool.cc
@@ -1973,7 +1973,9 @@ class Benchmark {
   int64_t max_num_range_tombstones_;
   WriteOptions write_options_;
   Options open_options_;  // keep options around to properly destroy db later
+#ifndef ROCKSDB_LITE
   TraceOptions trace_options_;
+#endif
   int64_t reads_;
   int64_t deletes_;
   double read_random_exp_range_;
@@ -4229,7 +4231,7 @@ void VerifyDBFromDB(std::string& truth_d
         }
         if (levelMeta.level == 0) {
           for (auto& fileMeta : levelMeta.files) {
-            fprintf(stdout, "Level[%d]: %s(size: %" PRIu64 " bytes)\n",
+            fprintf(stdout, "Level[%d]: %s(size: %" ROCKSDB_PRIszt " bytes)\n",
                     levelMeta.level, fileMeta.name.c_str(), fileMeta.size);
           }
         } else {
