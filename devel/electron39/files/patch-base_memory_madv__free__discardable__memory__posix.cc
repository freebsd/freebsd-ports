--- base/memory/madv_free_discardable_memory_posix.cc.orig	2025-10-21 20:19:54 UTC
+++ base/memory/madv_free_discardable_memory_posix.cc
@@ -297,6 +297,10 @@ bool MadvFreeDiscardableMemoryPosix::IsResident() cons
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
+// XXX mincore
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
 #if BUILDFLAG(IS_APPLE)
   std::vector<char> vec(allocated_pages_);
 #else
@@ -313,6 +317,7 @@ bool MadvFreeDiscardableMemoryPosix::IsResident() cons
     }
   }
   return true;
+#endif
 }
 
 bool MadvFreeDiscardableMemoryPosix::IsDiscarded() const {
