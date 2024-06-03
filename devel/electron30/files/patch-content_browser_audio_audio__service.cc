--- content/browser/audio/audio_service.cc.orig	2024-02-21 00:20:44 UTC
+++ content/browser/audio/audio_service.cc
@@ -34,7 +34,7 @@
 #if BUILDFLAG(ENABLE_PASSTHROUGH_AUDIO_CODECS)
 #include "ui/display/util/edid_parser.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/display/display_util.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -202,7 +202,7 @@ audio::mojom::AudioService& GetAudioService() {
         ->PostTaskAndReplyWithResult(
             FROM_HERE, base::BindOnce(&ScanEdidBitstreams),
             base::BindOnce(&LaunchAudioService, std::move(receiver)));
-#elif BUILDFLAG(ENABLE_PASSTHROUGH_AUDIO_CODECS) && BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(ENABLE_PASSTHROUGH_AUDIO_CODECS) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     LaunchAudioService(
         std::move(receiver),
         ConvertEdidBitstreams(display::DisplayUtil::GetAudioFormats()));
