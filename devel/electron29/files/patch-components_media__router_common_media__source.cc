--- components/media_router/common/media_source.cc.orig	2024-02-21 00:20:41 UTC
+++ components/media_router/common/media_source.cc
@@ -59,7 +59,7 @@ bool IsSystemAudioCaptureSupported() {
   }
 #if BUILDFLAG(IS_MAC)
   return base::FeatureList::IsEnabled(media::kMacLoopbackAudioForCast);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
 #else
   return true;
