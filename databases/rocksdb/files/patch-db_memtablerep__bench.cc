--- db/memtablerep_bench.cc.orig	2015-03-25 21:40:41 UTC
+++ db/memtablerep_bench.cc
@@ -132,7 +132,7 @@ DEFINE_int64(seed, 0,
              "Seed base for random number generators. "
              "When 0 it is deterministic.");
 
-static rocksdb::Env* FLAGS_env = rocksdb::Env::Default();
+//static rocksdb::Env* FLAGS_env = rocksdb::Env::Default();
 
 namespace rocksdb {
 
