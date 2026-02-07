--- deps/leveldb/port/atomic_pointer.h.orig	2021-05-20 13:33:22 UTC
+++ deps/leveldb/port/atomic_pointer.h
@@ -116,7 +116,7 @@ class AtomicPointer {
 
 // AtomicPointer based on <cstdatomic>
 #elif defined(LEVELDB_CSTDATOMIC_PRESENT)
-#include <cstdatomic>
+#include <atomic>
 
 class AtomicPointer {
  private:
