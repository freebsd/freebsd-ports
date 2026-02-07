--- media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2025-04-22 20:15:27 UTC
+++ media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -68,7 +68,7 @@ viz::SharedImageFormat GetSharedImageFormat(gfx::Buffe
                     << static_cast<int>(buffer_format);
       NOTREACHED();
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (format.is_multi_plane()) {
