--- components/live_caption/caption_util.cc.orig	2022-07-22 17:30:31 UTC
+++ components/live_caption/caption_util.cc
@@ -140,7 +140,7 @@ bool IsLiveCaptionFeatureSupported() {
     return false;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check if the CPU has the required instruction set to run the Speech
   // On-Device API (SODA) library.
   static bool has_sse41 = base::CPU().has_sse41();
