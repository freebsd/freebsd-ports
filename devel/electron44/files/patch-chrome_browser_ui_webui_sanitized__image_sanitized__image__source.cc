--- chrome/browser/ui/webui/sanitized_image/sanitized_image_source.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/ui/webui/sanitized_image/sanitized_image_source.cc
@@ -350,7 +350,7 @@ void SanitizedImageSource::OnAnimationDecoded(
   }
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mojo_frames.size() > 1) {
     // The image is animated, re-encode as WebP animated image and send to
     // requester.
