--- third_party/blink/renderer/platform/widget/compositing/categorized_worker_pool.cc.orig	2022-09-24 10:57:32 UTC
+++ third_party/blink/renderer/platform/widget/compositing/categorized_worker_pool.cc
@@ -256,7 +256,7 @@ void CategorizedWorkerPool::Start(int num_normal_threa
       "CompositorTileWorkerBackground", thread_options, this,
       background_thread_prio_categories,
       &has_task_for_background_priority_thread_cv_);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   thread->SetBackgroundingCallback(
       Thread::MainThread()->GetDeprecatedTaskRunner(),
       base::BindOnce([](base::PlatformThreadId thread_id) {
