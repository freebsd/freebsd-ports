--- components/viz/service/display_embedder/skia_output_surface_impl_on_gpu.cc.orig	2023-10-19 19:58:21 UTC
+++ components/viz/service/display_embedder/skia_output_surface_impl_on_gpu.cc
@@ -1521,7 +1521,12 @@ void SkiaOutputSurfaceImplOnGpu::CopyOutputNV12(
 
       // Issue readbacks from the surfaces:
       for (size_t i = 0; i < CopyOutputResult::kNV12MaxPlanes; ++i) {
+#if defined(__clang__) && (__clang_major__ >= 16)
         SkISize size(plane_surfaces[i]->width(), plane_surfaces[i]->height());
+#else
+        SkISize s = { plane_surfaces[i]->width(), plane_surfaces[i]->height() };
+        SkISize size(s);
+#endif
         SkImageInfo dst_info = SkImageInfo::Make(
             size, (i == 0) ? kAlpha_8_SkColorType : kR8G8_unorm_SkColorType,
             kUnpremul_SkAlphaType);
