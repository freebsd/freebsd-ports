--- base/debug/stack_trace_posix.cc.orig	2019-03-15 06:36:56 UTC
+++ base/debug/stack_trace_posix.cc
@@ -35,7 +35,7 @@
 #include <AvailabilityMacros.h>
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/debug/proc_maps_linux.h"
 #endif
 
@@ -646,6 +646,11 @@ class SandboxSymbolizeHelper {
   // for the modules that are loaded in the current process.
   // Returns true on success.
   bool CacheMemoryRegions() {
+#if defined(OS_BSD)
+    // TODO (rene) avoid link error, implement something?
+    NOTIMPLEMENTED();
+    return false;
+#else
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
@@ -663,6 +668,7 @@ class SandboxSymbolizeHelper {
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
@@ -800,7 +806,7 @@ StackTrace::StackTrace(size_t count) {
 // NOTE: This code MUST be async-signal safe (it's used by in-process
 // stack dumping signal handler). NO malloc or stdio is allowed here.
 
-#if !defined(__UCLIBC__) && !defined(_AIX)
+#if !defined(__UCLIBC__) && !defined(_AIX) && !defined(OS_BSD)
   count = std::min(arraysize(trace_), count);
 
   // Though the backtrace API man page does not list any possible negative
