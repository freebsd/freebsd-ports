--- electron/shell/common/api/electron_api_native_image.h.orig	2022-05-11 15:32:29 UTC
+++ electron/shell/common/api/electron_api_native_image.h
@@ -78,7 +78,7 @@ class NativeImage : public gin::Wrappable<NativeImage>
                                                     const GURL& url);
   static gin::Handle<NativeImage> CreateFromNamedImage(gin::Arguments* args,
                                                        std::string name);
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   static v8::Local<v8::Promise> CreateThumbnailFromPath(
       v8::Isolate* isolate,
       const base::FilePath& path,
