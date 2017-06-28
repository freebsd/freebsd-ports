--- storage/rocksdb/rocksdb/db/db_impl.cc.orig	2017-05-25 21:54:40 UTC
+++ storage/rocksdb/rocksdb/db/db_impl.cc
@@ -18,7 +18,7 @@
 #ifdef OS_SOLARIS
 #include <alloca.h>
 #endif
-#ifdef ROCKSDB_JEMALLOC
+#if defined(ROCKSDB_JEMALLOC) && !defined(__FreeBSD__)
 #include "jemalloc/jemalloc.h"
 #endif
 
@@ -400,7 +400,11 @@ static void DumpMallocStats(std::string*
   std::unique_ptr<char[]> buf{new char[kMallocStatusLen + 1]};
   mstat.cur = buf.get();
   mstat.end = buf.get() + kMallocStatusLen;
+#ifdef __FreeBSD__
+  __malloc_stats_print(GetJemallocStatus, &mstat, "");
+#else
   je_malloc_stats_print(GetJemallocStatus, &mstat, "");
+#endif
   stats->append(buf.get());
 #endif  // ROCKSDB_JEMALLOC
 }
