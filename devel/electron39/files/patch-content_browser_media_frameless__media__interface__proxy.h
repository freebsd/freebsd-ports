--- content/browser/media/frameless_media_interface_proxy.h.orig	2025-06-30 07:04:30 UTC
+++ content/browser/media/frameless_media_interface_proxy.h
@@ -19,7 +19,7 @@
 #include "mojo/public/cpp/bindings/receiver_set.h"
 #include "mojo/public/cpp/bindings/remote.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/mojo/mojom/video_decoder.mojom.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -98,7 +98,7 @@ class FramelessMediaInterfaceProxy final
   // Connections to the renderer.
   mojo::ReceiverSet<media::mojom::InterfaceFactory> receivers_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Connection to the InterfaceFactory that lives in a utility process.
   // This is only used for out-of-process video decoding and only when the
   // FramelessMediaInterfaceProxy is created without a RenderProcessHost
