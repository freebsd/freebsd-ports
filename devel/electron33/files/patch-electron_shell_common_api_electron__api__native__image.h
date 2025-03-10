--- electron/shell/common/api/electron_api_native_image.h.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/common/api/electron_api_native_image.h
@@ -80,7 +80,7 @@ class NativeImage final : public gin::Wrappable<Native
                                                     const GURL& url);
   static gin::Handle<NativeImage> CreateFromNamedImage(gin::Arguments* args,
                                                        std::string name);
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   static v8::Local<v8::Promise> CreateThumbnailFromPath(
       v8::Isolate* isolate,
       const base::FilePath& path,
