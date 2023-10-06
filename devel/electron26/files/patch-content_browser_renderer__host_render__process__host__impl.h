--- content/browser/renderer_host/render_process_host_impl.h.orig	2023-08-10 01:48:43 UTC
+++ content/browser/renderer_host/render_process_host_impl.h
@@ -537,7 +537,7 @@ class CONTENT_EXPORT RenderProcessHostImpl
   // Sets this RenderProcessHost to be guest only. For Testing only.
   void SetForGuestsOnlyForTesting();
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Launch the zygote early in the browser startup.
   static void EarlyZygoteLaunch();
 #endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
