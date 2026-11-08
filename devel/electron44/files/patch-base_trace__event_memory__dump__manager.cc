--- base/trace_event/memory_dump_manager.cc.orig	2026-06-23 23:37:18 UTC
+++ base/trace_event/memory_dump_manager.cc
@@ -86,7 +86,7 @@ const char* const MemoryDumpManager::kSystemAllocatorP
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
