--- electron/shell/common/api/electron_api_native_image.h.orig	2022-06-08 15:30:58 UTC
+++ electron/shell/common/api/electron_api_native_image.h
@@ -79,7 +79,7 @@ class NativeImage : public gin::Wrappable<NativeImage>
                                                     const GURL& url);
   static gin::Handle<NativeImage> CreateFromNamedImage(gin::Arguments* args,
                                                        std::string name);
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   static v8::Local<v8::Promise> CreateThumbnailFromPath(
       v8::Isolate* isolate,
       const base::FilePath& path,
