--- electron/shell/common/api/electron_api_shared_texture.cc.orig	2026-02-04 19:30:54 UTC
+++ electron/shell/common/api/electron_api_shared_texture.cc
@@ -27,7 +27,7 @@
 #include "third_party/blink/renderer/platform/graphics/gpu/shared_gpu_context.h"  // nogncheck
 #include "ui/compositor/compositor.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/posix/eintr_wrapper.h"
 #include "base/strings/string_number_conversions.h"
 #endif
@@ -538,7 +538,7 @@ struct ImportSharedTextureInfo {
   // On macOS, it is an IOSurfaceRef, this must be a valid IOSurface at the
   // current process.
   uintptr_t io_surface = 0;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, to be implemented.
   std::vector<ImportSharedTextureInfoPlane> planes;
   uint64_t modifier = gfx::NativePixmapHandle::kNoModifier;
@@ -604,7 +604,7 @@ struct Converter<ImportSharedTextureInfo> {
     GetNativeHandle("ntHandle", &out->nt_handle);
 #elif BUILDFLAG(IS_APPLE)
     GetNativeHandle("ioSurface", &out->io_surface);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     v8::Local<v8::Object> native_pixmap;
     if (shared_texture.Get("nativePixmap", &native_pixmap)) {
       gin::Dictionary v8_native_pixmap(isolate, native_pixmap);
@@ -680,7 +680,7 @@ v8::Local<v8::Value> ImportSharedTexture(v8::Isolate* 
   auto io_surface_scoped = base::apple::ScopedCFTypeRef<IOSurfaceRef>(
       io_surface, base::scoped_policy::RETAIN);
   gmb_handle = gfx::GpuMemoryBufferHandle(std::move(io_surface_scoped));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gfx::NativePixmapHandle pixmap;
   pixmap.modifier = shared_texture.modifier;
   pixmap.supports_zero_copy_webgpu_import =
