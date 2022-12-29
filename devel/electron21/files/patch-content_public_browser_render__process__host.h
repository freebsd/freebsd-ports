--- content/public/browser/render_process_host.h.orig	2022-09-24 10:57:32 UTC
+++ content/public/browser/render_process_host.h
@@ -53,7 +53,7 @@
 #include "content/public/browser/android/child_process_importance.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/mojo/mojom/stable/stable_video_decoder.mojom-forward.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -626,7 +626,7 @@ class CONTENT_EXPORT RenderProcessHost : public IPC::S
       const blink::StorageKey& storage_key,
       mojo::PendingReceiver<blink::mojom::WebSocketConnector> receiver) = 0;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   virtual void CreateStableVideoDecoder(
       mojo::PendingReceiver<media::stable::mojom::StableVideoDecoder>
           receiver) = 0;
