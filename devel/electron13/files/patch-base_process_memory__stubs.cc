--- base/process/memory_stubs.cc.orig	2021-07-15 19:13:29 UTC
+++ base/process/memory_stubs.cc
@@ -19,9 +19,11 @@ bool AdjustOOMScore(ProcessId process, int score) {
   return false;
 }
 
+#if !defined(OS_BSD)
 void TerminateBecauseOutOfMemory(size_t size) {
   abort();
 }
+#endif
 
 // UncheckedMalloc and Calloc exist so that platforms making use of
 // EnableTerminationOnOutOfMemory have a way to allocate memory without
