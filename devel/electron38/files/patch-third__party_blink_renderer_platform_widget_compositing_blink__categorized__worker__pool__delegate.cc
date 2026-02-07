--- third_party/blink/renderer/platform/widget/compositing/blink_categorized_worker_pool_delegate.cc.orig	2023-05-25 00:42:05 UTC
+++ third_party/blink/renderer/platform/widget/compositing/blink_categorized_worker_pool_delegate.cc
@@ -27,7 +27,7 @@ BlinkCategorizedWorkerPoolDelegate& BlinkCategorizedWo
 
 void BlinkCategorizedWorkerPoolDelegate::NotifyThreadWillRun(
     base::PlatformThreadId tid) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   scoped_refptr<base::TaskRunner> task_runner =
       Thread::MainThread()->GetTaskRunner(MainThreadTaskRunnerRestricted());
   task_runner->PostTask(FROM_HERE, base::BindOnce(
