--- third_party/blink/renderer/platform/peerconnection/webrtc_util.cc.orig	2026-01-07 00:52:53 UTC
+++ third_party/blink/renderer/platform/peerconnection/webrtc_util.cc
@@ -23,7 +23,7 @@ namespace blink {
 namespace blink {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Enables H.264 CBP encode acceleration.
 BASE_FEATURE(kPlatformH264CbpEncoding,
 #if BUILDFLAG(IS_WIN)
@@ -126,7 +126,7 @@ IsH264ConstrainedBaselineProfileAvailableForAccelerate
 bool PLATFORM_EXPORT
 IsH264ConstrainedBaselineProfileAvailableForAcceleratedEncoder() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(kPlatformH264CbpEncoding);
 #else
   return false;
