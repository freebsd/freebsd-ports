--- electron/shell/common/api/electron_api_native_image.cc.orig	2022-05-04 15:34:10 UTC
+++ electron/shell/common/api/electron_api_native_image.cc
@@ -642,7 +642,7 @@ void Initialize(v8::Local<v8::Object> exports,
   native_image.SetMethod("createFromDataURL", &NativeImage::CreateFromDataURL);
   native_image.SetMethod("createFromNamedImage",
                          &NativeImage::CreateFromNamedImage);
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   native_image.SetMethod("createThumbnailFromPath",
                          &NativeImage::CreateThumbnailFromPath);
 #endif
