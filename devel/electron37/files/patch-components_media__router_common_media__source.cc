--- components/media_router/common/media_source.cc.orig	2025-06-30 07:04:30 UTC
+++ components/media_router/common/media_source.cc
@@ -58,7 +58,7 @@ bool IsSystemAudioCaptureSupported() {
   if (!media::IsSystemLoopbackCaptureSupported()) {
     return false;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
 #else
   return true;
