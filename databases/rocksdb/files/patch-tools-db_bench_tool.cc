--- tools/db_bench_tool.cc.orig	2018-11-12 19:57:32 UTC
+++ tools/db_bench_tool.cc
@@ -4229,7 +4229,7 @@ void VerifyDBFromDB(std::string& truth_d
         }
         if (levelMeta.level == 0) {
           for (auto& fileMeta : levelMeta.files) {
-            fprintf(stdout, "Level[%d]: %s(size: %" PRIu64 " bytes)\n",
+            fprintf(stdout, "Level[%d]: %s(size: %" ROCKSDB_PRIszt " bytes)\n",
                     levelMeta.level, fileMeta.name.c_str(), fileMeta.size);
           }
         } else {
