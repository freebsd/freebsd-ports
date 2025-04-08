--- electron/shell/browser/osr/osr_paint_event.h.orig	2024-11-11 11:23:02 UTC
+++ electron/shell/browser/osr/osr_paint_event.h
@@ -96,7 +96,7 @@ struct OffscreenSharedTextureValue {
   // On Windows it is a HANDLE to the shared D3D11 texture.
   // On macOS it is a IOSurface* to the shared IOSurface.
   uintptr_t shared_texture_handle;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::vector<OffscreenNativePixmapPlaneInfo> planes;
   uint64_t modifier;
 #endif
