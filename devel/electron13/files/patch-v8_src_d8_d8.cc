--- v8/src/d8/d8.cc.orig	2021-07-15 19:15:58 UTC
+++ v8/src/d8/d8.cc
@@ -73,7 +73,7 @@
 #include "unicode/locid.h"
 #endif  // V8_INTL_SUPPORT
 
-#ifdef V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
 #include <sys/mman.h>  // For MultiMappedAllocator.
 #endif
 
@@ -235,7 +235,7 @@ class MockArrayBufferAllocatiorWithLimit : public Mock
   std::atomic<size_t> space_left_;
 };
 
-#ifdef V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
 
 // This is a mock allocator variant that provides a huge virtual allocation
 // backed by a small real allocation that is repeatedly mapped. If you create an
@@ -328,7 +328,7 @@ class MultiMappedAllocator : public ArrayBufferAllocat
   base::Mutex regions_mutex_;
 };
 
-#endif  // V8_OS_LINUX
+#endif  // V8_OS_LINUX || V8_OS_FREEBSD
 
 v8::Platform* g_default_platform;
 std::unique_ptr<v8::Platform> g_platform;
@@ -4099,7 +4099,7 @@ bool Shell::SetOptions(int argc, char* argv[]) {
   options.mock_arraybuffer_allocator = i::FLAG_mock_arraybuffer_allocator;
   options.mock_arraybuffer_allocator_limit =
       i::FLAG_mock_arraybuffer_allocator_limit;
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
   options.multi_mapped_mock_allocator = i::FLAG_multi_mapped_mock_allocator;
 #endif
 
@@ -4735,19 +4735,19 @@ int Shell::Main(int argc, char* argv[]) {
       memory_limit >= options.mock_arraybuffer_allocator_limit
           ? memory_limit
           : std::numeric_limits<size_t>::max());
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
   MultiMappedAllocator multi_mapped_mock_allocator;
-#endif  // V8_OS_LINUX
+#endif  // V8_OS_LINUX || V8_OS_FREEBSD
   if (options.mock_arraybuffer_allocator) {
     if (memory_limit) {
       Shell::array_buffer_allocator = &mock_arraybuffer_allocator_with_limit;
     } else {
       Shell::array_buffer_allocator = &mock_arraybuffer_allocator;
     }
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
   } else if (options.multi_mapped_mock_allocator) {
     Shell::array_buffer_allocator = &multi_mapped_mock_allocator;
-#endif  // V8_OS_LINUX
+#endif  // V8_OS_LINUX || V8_OS_FREEBSD
   } else {
     Shell::array_buffer_allocator = &shell_array_buffer_allocator;
   }
