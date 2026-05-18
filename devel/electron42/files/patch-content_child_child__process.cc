--- content/child/child_process.cc.orig	2026-03-13 16:54:03 UTC
+++ content/child/child_process.cc
@@ -36,7 +36,7 @@
 #include "content/common/android/cpu_time_metrics.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
 
@@ -204,7 +204,7 @@ void ChildProcess::set_main_thread(ChildThreadImpl* th
   main_thread_.reset(thread);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ChildProcess::SetIOThreadType(base::ThreadType thread_type) {
   if (!io_thread_) {
     return;
