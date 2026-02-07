--- base/process/memory_linux.cc.orig	2025-03-24 20:50:14 UTC
+++ base/process/memory_linux.cc
@@ -28,6 +28,7 @@ namespace base {
 
 namespace base {
 
+#if !BUILDFLAG(IS_BSD)
 namespace {
 
 void ReleaseReservationOrTerminate() {
@@ -38,12 +39,14 @@ void ReleaseReservationOrTerminate() {
 }
 
 }  // namespace
+#endif
 
 void EnableTerminationOnHeapCorruption() {
   // On Linux, there nothing to do AFAIK.
 }
 
 void EnableTerminationOnOutOfMemory() {
+#if !BUILDFLAG(IS_BSD)
   // Set the new-out of memory handler.
   std::set_new_handler(&ReleaseReservationOrTerminate);
   // If we're using glibc's allocator, the above functions will override
@@ -52,8 +55,10 @@ void EnableTerminationOnOutOfMemory() {
 #if PA_BUILDFLAG(USE_ALLOCATOR_SHIM)
   allocator_shim::SetCallNewHandlerOnMallocFailure(true);
 #endif
+#endif
 }
 
+#if !BUILDFLAG(IS_BSD)
 // ScopedAllowBlocking() has private constructor and it can only be used in
 // friend classes/functions. Declaring a class is easier in this situation to
 // avoid adding more dependency to thread_restrictions.h because of the
@@ -111,6 +116,7 @@ bool AdjustOOMScore(ProcessId process, int score) {
 bool AdjustOOMScore(ProcessId process, int score) {
   return AdjustOOMScoreHelper::AdjustOOMScore(process, score);
 }
+#endif
 
 bool UncheckedMalloc(size_t size, void** result) {
 #if PA_BUILDFLAG(USE_ALLOCATOR_SHIM)
