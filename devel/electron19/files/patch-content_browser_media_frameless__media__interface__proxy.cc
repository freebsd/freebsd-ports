--- content/browser/media/frameless_media_interface_proxy.cc.orig	2022-05-25 04:01:00 UTC
+++ content/browser/media/frameless_media_interface_proxy.cc
@@ -15,7 +15,7 @@
 #include "media/mojo/mojom/renderer_extensions.mojom.h"
 #include "media/mojo/mojom/stable/stable_video_decoder.mojom.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/public/browser/stable_video_decoder_factory.h"
 #include "media/base/media_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -64,7 +64,7 @@ void FramelessMediaInterfaceProxy::CreateVideoDecoder(
 
   mojo::PendingRemote<media::stable::mojom::StableVideoDecoder>
       oop_video_decoder;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(media::kUseOutOfProcessVideoDecoding)) {
     // TODO(b/195769334): for now, we're using the same
     // StableVideoDecoderFactory. However, we should be using a separate
