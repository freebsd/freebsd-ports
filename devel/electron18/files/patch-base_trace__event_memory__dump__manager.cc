--- base/trace_event/memory_dump_manager.cc.orig	2022-05-19 05:17:34 UTC
+++ base/trace_event/memory_dump_manager.cc
@@ -82,7 +82,7 @@ const char* const MemoryDumpManager::kSystemAllocatorP
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
