--- media/mojo/mojom/video_frame_mojom_traits.h.orig	2025-04-22 20:15:27 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.h
@@ -21,7 +21,7 @@ namespace mojo {
 
 namespace mojo {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 template <>
 struct StructTraits<media::mojom::ColorPlaneLayoutDataView,
                     media::ColorPlaneLayout> {
