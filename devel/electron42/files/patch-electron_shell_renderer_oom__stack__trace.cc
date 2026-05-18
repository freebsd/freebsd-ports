--- electron/shell/renderer/oom_stack_trace.cc.orig	2026-05-12 21:06:23 UTC
+++ electron/shell/renderer/oom_stack_trace.cc
@@ -119,7 +119,7 @@ void CaptureStackOnInterrupt(v8::Isolate* isolate, voi
 
   std::string js_stack = FormatStackTrace(isolate, stack);
   if (!js_stack.empty()) {
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
     crash_keys::SetCrashKey("electron.v8-oom.stack", js_stack);
 #endif
     LOG(ERROR) << "\n<--- JS stacktrace (captured at safe point) --->\n"
@@ -150,7 +150,7 @@ size_t NearHeapLimitCallback(void* data,
                                           stats.heap_size_limit() / 1048576.0);
   LOG(ERROR) << "\n<--- Near heap limit --->\n" << heap_info;
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   crash_keys::SetCrashKey("electron.v8-oom.stack",
                           heap_info + " (stack pending)");
 
@@ -226,7 +226,7 @@ size_t NearHeapLimitCallback(void* data,
   if (current_heap_limit >= kCageLimit - kHeapBump) {
     // The bump will be clamped by V8 to the cage ceiling, leaving no
     // headroom for the interrupt to fire. Record what we can now.
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
     crash_keys::SetCrashKey("electron.v8-oom.stack",
                             heap_info + " (at cage limit, stack unavailable)");
 #endif
