--- media/mojo/mojom/video_frame_mojom_traits.h.orig	2026-03-13 16:54:03 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.h
@@ -19,7 +19,7 @@ namespace mojo {
 
 namespace mojo {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 template <>
 struct StructTraits<media::mojom::ColorPlaneLayoutDataView,
                     media::ColorPlaneLayout> {
