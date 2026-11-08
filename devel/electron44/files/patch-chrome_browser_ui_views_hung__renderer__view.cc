--- chrome/browser/ui/views/hung_renderer_view.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/ui/views/hung_renderer_view.cc
@@ -452,7 +452,7 @@ void HungRendererDialogView::ForceCrashHungRenderer() 
   content::RenderProcessHost* rph =
       hung_pages_table_model_->GetRenderWidgetHost()->GetProcess();
   if (rph) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // A generic |CrashDumpHungChildProcess()| is not implemented for Linux.
     // Instead we send an explicit IPC to crash on the renderer's IO thread.
     rph->ForceCrash();
