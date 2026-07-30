--- electron/shell/common/api/electron_api_native_image.cc.orig	2026-07-28 14:50:45 UTC
+++ electron/shell/common/api/electron_api_native_image.cc
@@ -654,7 +654,7 @@ void Initialize(v8::Local<v8::Object> exports,
   native_image.SetMethod("createFromDataURL", &NativeImage::CreateFromDataURL);
   native_image.SetMethod("createFromNamedImage",
                          &NativeImage::CreateFromNamedImage);
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   native_image.SetMethod("createThumbnailFromPath",
                          &NativeImage::CreateThumbnailFromPath);
 #endif
