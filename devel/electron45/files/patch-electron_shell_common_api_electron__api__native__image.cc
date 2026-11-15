--- electron/shell/common/api/electron_api_native_image.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/common/api/electron_api_native_image.cc
@@ -675,7 +675,7 @@ void Initialize(v8::Local<v8::Object> exports,
   native_image.SetMethod<&NativeImage::CreateFromNamedImage>(
       "createFromNamedImage");
   native_image.SetMethod<&NativeImage::CreateMenuSymbol>("createMenuSymbol");
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   native_image.SetMethod<&NativeImage::CreateThumbnailFromPath>(
       "createThumbnailFromPath");
 #endif
