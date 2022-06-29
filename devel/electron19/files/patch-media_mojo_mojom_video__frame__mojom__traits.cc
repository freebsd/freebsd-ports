--- media/mojo/mojom/video_frame_mojom_traits.cc.orig	2022-05-25 04:01:04 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.cc
@@ -23,7 +23,7 @@
 #include "ui/gfx/mojom/color_space_mojom_traits.h"
 #include "ui/gfx/mojom/hdr_metadata_mojom_traits.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/posix/eintr_wrapper.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
