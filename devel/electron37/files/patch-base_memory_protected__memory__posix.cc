--- base/memory/protected_memory_posix.cc.orig	2024-10-16 21:30:44 UTC
+++ base/memory/protected_memory_posix.cc
@@ -6,7 +6,7 @@
 
 #include <sys/mman.h>
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -34,7 +34,7 @@ namespace internal {
 }  // namespace
 
 namespace internal {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void CheckMemoryReadOnly(const void* ptr) {
   const uintptr_t page_start =
       bits::AlignDown(reinterpret_cast<uintptr_t>(ptr), GetPageSize());
