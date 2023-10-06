--- base/memory/madv_free_discardable_memory_posix.cc.orig	2023-05-25 00:41:38 UTC
+++ base/memory/madv_free_discardable_memory_posix.cc
@@ -306,6 +306,10 @@ void MadvFreeDiscardableMemoryPosix::SetKeepMemoryForT
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
+// XXX mincore
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
 #if BUILDFLAG(IS_APPLE)
   std::vector<char> vec(allocated_pages_);
 #else
@@ -321,6 +325,7 @@ bool MadvFreeDiscardableMemoryPosix::IsResident() cons
       return false;
   }
   return true;
+#endif
 }
 
 bool MadvFreeDiscardableMemoryPosix::IsDiscarded() const {
