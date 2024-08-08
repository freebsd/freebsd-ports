--- base/memory/madv_free_discardable_memory_posix.cc.orig	2024-06-18 21:43:17 UTC
+++ base/memory/madv_free_discardable_memory_posix.cc
@@ -311,6 +311,10 @@ bool MadvFreeDiscardableMemoryPosix::IsResident() cons
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
+// XXX mincore
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
 #if BUILDFLAG(IS_APPLE)
   std::vector<char> vec(allocated_pages_);
 #else
@@ -326,6 +330,7 @@ bool MadvFreeDiscardableMemoryPosix::IsResident() cons
       return false;
   }
   return true;
+#endif
 }
 
 bool MadvFreeDiscardableMemoryPosix::IsDiscarded() const {
