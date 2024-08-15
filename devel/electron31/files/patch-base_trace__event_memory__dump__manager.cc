--- base/trace_event/memory_dump_manager.cc.orig	2024-06-18 21:43:18 UTC
+++ base/trace_event/memory_dump_manager.cc
@@ -87,7 +87,7 @@ const char* const MemoryDumpManager::kSystemAllocatorP
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
