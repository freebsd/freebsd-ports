--- electron/shell/browser/osr/osr_paint_event.h.orig	2025-10-27 17:58:27 UTC
+++ electron/shell/browser/osr/osr_paint_event.h
@@ -99,7 +99,7 @@ struct OffscreenSharedTextureValue {
   // On Windows it is a HANDLE to the shared D3D11 texture.
   // On macOS it is a IOSurface* to the shared IOSurface.
   uintptr_t shared_texture_handle;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::vector<OffscreenNativePixmapPlaneInfo> planes;
   uint64_t modifier;
   bool supports_zero_copy_webgpu_import;
