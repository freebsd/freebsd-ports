--- storage/rocksdb/rocksdb/db/malloc_stats.cc.orig	2017-08-17 10:05:38 UTC
+++ storage/rocksdb/rocksdb/db/malloc_stats.cc
@@ -16,7 +16,12 @@
 namespace rocksdb {
 
 #ifdef ROCKSDB_JEMALLOC
+#ifdef __FreeBSD__
+#include <malloc_np.h>
+#define je_malloc_stats_print malloc_stats_print
+#else
 #include "jemalloc/jemalloc.h"
+#endif
 
 typedef struct {
   char* cur;
