--- electron/shell/common/api/electron_api_native_image.cc.orig	2026-09-29 23:27:57 UTC
+++ electron/shell/common/api/electron_api_native_image.cc
@@ -676,7 +676,7 @@ void Initialize(v8::Local<v8::Object> exports,
   native_image.SetMethod("createFromNamedImage",
                          &NativeImage::CreateFromNamedImage);
   native_image.SetMethod("createMenuSymbol", &NativeImage::CreateMenuSymbol);
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   native_image.SetMethod("createThumbnailFromPath",
                          &NativeImage::CreateThumbnailFromPath);
 #endif
