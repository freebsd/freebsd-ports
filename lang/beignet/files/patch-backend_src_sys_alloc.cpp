--- backend/src/sys/alloc.cpp.orig	2017-01-20 10:40:51 UTC
+++ backend/src/sys/alloc.cpp
@@ -69,7 +69,7 @@ namespace gbe
     /*! Total number of allocations done */
     volatile intptr_t allocNum;
     /*! Sorts the file name and function name strings */
-    std::tr1::unordered_map<const char*, int> staticStringMap;
+    std::unordered_map<const char*, int> staticStringMap;
     /*! Each element contains the actual string */
     std::vector<const char*> staticStringVector;
     std::map<uintptr_t, AllocData> allocMap;
@@ -140,16 +140,17 @@ namespace gbe
   static bool isMutexInitializing = true;
   static size_t memDebuggerCurrSize(0u);
   static size_t memDebuggerMaxSize(0u);
+  __attribute__((destructor))
   static void SizeMutexDeallocate(void) { if (sizeMutex) delete sizeMutex; }
   static void SizeMutexAllocate(void) {
     if (sizeMutex == NULL && isMutexInitializing == false) {
       isMutexInitializing = true;
       sizeMutex = new MutexSys;
-      atexit(SizeMutexDeallocate);
     }
   }
 
   /*! Stop the memory debugger */
+  __attribute__((destructor))
   static void MemDebuggerEnd(void) {
     MemDebugger *_debug = memDebugger;
     memDebugger = NULL;
@@ -172,7 +173,6 @@ namespace gbe
   /*! Start the memory debugger */
   static void MemDebuggerStart(void) {
     if (memDebugger == NULL) {
-      atexit(MemDebuggerEnd);
       memDebugger = new MemDebugger;
     }
   }
@@ -291,6 +291,29 @@ namespace gbe
   void alignedFree(void *ptr) { if (ptr) std::free(ptr); }
 } /* namespace gbe */
 
+#elif defined(__FreeBSD__)
+
+#include <unistd.h>
+#include <sys/mman.h>
+#include <fcntl.h>
+#include <stdlib.h>
+#include <malloc_np.h>
+#include <iostream>
+
+namespace gbe
+{
+  void* alignedMalloc(size_t size, size_t align) {
+    void* ptr;
+    const int err = posix_memalign(&ptr,align,size);
+    FATAL_IF ((err != 0), "memory allocation failed");
+    MemDebuggerInitializeMem(ptr, size);
+    return ptr;
+  }
+
+  void alignedFree(void *ptr) { if (ptr) std::free(ptr); }
+} /* namespace gbe */
+
+
 #else
 #error "Unsupported platform"
 #endif /* __LINUX__ */
