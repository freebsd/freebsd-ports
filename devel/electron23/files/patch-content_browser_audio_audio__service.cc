--- content/browser/audio/audio_service.cc.orig	2023-02-01 18:43:19 UTC
+++ content/browser/audio/audio_service.cc
@@ -33,7 +33,7 @@
 #if BUILDFLAG(ENABLE_PASSTHROUGH_AUDIO_CODECS)
 #include "ui/display/util/edid_parser.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/display/display_util.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -213,7 +213,7 @@ audio::mojom::AudioService& GetAudioService() {
         ->PostTaskAndReplyWithResult(
             FROM_HERE, base::BindOnce(&ScanEdidBitstreams),
             base::BindOnce(&LaunchAudioService, std::move(receiver)));
-#elif BUILDFLAG(ENABLE_PASSTHROUGH_AUDIO_CODECS) && BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(ENABLE_PASSTHROUGH_AUDIO_CODECS) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     LaunchAudioService(
         std::move(receiver),
         ConvertEdidBitstreams(display::DisplayUtil::GetAudioFormats()));
