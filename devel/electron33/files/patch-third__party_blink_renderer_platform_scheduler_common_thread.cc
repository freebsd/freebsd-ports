--- third_party/blink/renderer/platform/scheduler/common/thread.cc.orig	2024-10-16 21:31:46 UTC
+++ third_party/blink/renderer/platform/scheduler/common/thread.cc
@@ -88,7 +88,7 @@ void Thread::CreateAndSetCompositorThread() {
             "Compositor");
       }));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_OPENBSD)
   compositor_thread->GetTaskRunner()->PostTaskAndReplyWithResult(
       FROM_HERE, base::BindOnce(&base::PlatformThread::CurrentId),
       base::BindOnce([](base::PlatformThreadId compositor_thread_id) {
