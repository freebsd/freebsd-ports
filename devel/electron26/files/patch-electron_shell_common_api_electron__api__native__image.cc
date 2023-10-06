--- electron/shell/common/api/electron_api_native_image.cc.orig	2023-08-14 18:19:06 UTC
+++ electron/shell/common/api/electron_api_native_image.cc
@@ -653,7 +653,7 @@ void Initialize(v8::Local<v8::Object> exports,
   native_image.SetMethod("createFromDataURL", &NativeImage::CreateFromDataURL);
   native_image.SetMethod("createFromNamedImage",
                          &NativeImage::CreateFromNamedImage);
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   native_image.SetMethod("createThumbnailFromPath",
                          &NativeImage::CreateThumbnailFromPath);
 #endif
