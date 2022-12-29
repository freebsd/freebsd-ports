--- content/browser/renderer_host/render_process_host_impl.h.orig	2022-09-24 10:57:32 UTC
+++ content/browser/renderer_host/render_process_host_impl.h
@@ -83,7 +83,7 @@
 #include "content/public/browser/android/child_process_importance.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/mojo/mojom/stable/stable_video_decoder.mojom.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -472,7 +472,7 @@ class CONTENT_EXPORT RenderProcessHostImpl
   // Sets this RenderProcessHost to be guest only. For Testing only.
   void SetForGuestsOnlyForTesting();
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Launch the zygote early in the browser startup.
   static void EarlyZygoteLaunch();
 #endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
@@ -671,7 +671,7 @@ class CONTENT_EXPORT RenderProcessHostImpl
       mojo::PendingReceiver<blink::mojom::WebSocketConnector> receiver)
       override;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void CreateStableVideoDecoder(
       mojo::PendingReceiver<media::stable::mojom::StableVideoDecoder> receiver)
       override;
@@ -1121,7 +1121,7 @@ class CONTENT_EXPORT RenderProcessHostImpl
   // RenderProcessHost. This is destroyed early in ResetIPC() method.
   std::unique_ptr<PermissionServiceContext> permission_service_context_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Connection to the StableVideoDecoderFactory that lives in a utility
   // process. This is only used for out-of-process video decoding.
   mojo::Remote<media::stable::mojom::StableVideoDecoderFactory>
