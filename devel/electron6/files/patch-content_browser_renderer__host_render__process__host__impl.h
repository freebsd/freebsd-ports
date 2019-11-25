--- content/browser/renderer_host/render_process_host_impl.h.orig	2019-09-10 11:14:02 UTC
+++ content/browser/renderer_host/render_process_host_impl.h
@@ -400,10 +400,10 @@ class CONTENT_EXPORT RenderProcessHostImpl
     is_for_guests_only_ = is_for_guests_only;
   }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Launch the zygote early in the browser startup.
   static void EarlyZygoteLaunch();
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
   RendererAudioOutputStreamFactoryContext*
   GetRendererAudioOutputStreamFactoryContext() override;
