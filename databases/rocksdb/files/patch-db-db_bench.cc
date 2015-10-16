--- db/db_bench.cc.orig	2015-08-31 20:23:39.000000000 +0200
+++ db/db_bench.cc	2015-09-08 00:15:47.039650000 +0200
@@ -2259,8 +2259,7 @@ class Benchmark {
         fprintf(stderr, "Open flash device failed\n");
         exit(1);
       }
-      flashcache_aware_env_ =
-          std::move(NewFlashcacheAwareEnv(FLAGS_env, cachedev_fd_));
+      flashcache_aware_env_ = NewFlashcacheAwareEnv(FLAGS_env, cachedev_fd_);
       if (flashcache_aware_env_.get() == nullptr) {
         fprintf(stderr, "Failed to open flashcahce device at %s\n",
                 FLAGS_flashcache_dev.c_str());
@@ -2884,7 +2883,7 @@ class Benchmark {
     std::vector<std::unique_ptr<const char[]> > key_guards;
     std::vector<std::string> values(entries_per_batch_);
     while (static_cast<int64_t>(keys.size()) < entries_per_batch_) {
-      key_guards.push_back(std::move(std::unique_ptr<const char[]>()));
+      key_guards.push_back(std::unique_ptr<const char[]>());
       keys.push_back(AllocateKey(&key_guards.back()));
     }
 
