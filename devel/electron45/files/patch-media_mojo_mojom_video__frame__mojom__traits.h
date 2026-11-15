--- media/mojo/mojom/video_frame_mojom_traits.h.orig	2026-06-23 23:37:18 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.h
@@ -18,7 +18,7 @@ namespace mojo {
 
 namespace mojo {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 template <>
 struct StructTraits<media::mojom::ColorPlaneLayoutDataView,
                     media::ColorPlaneLayout> {
