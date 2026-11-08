--- electron/shell/common/api/electron_api_native_image.h.orig	2026-06-29 20:35:15 UTC
+++ electron/shell/common/api/electron_api_native_image.h
@@ -73,7 +73,7 @@ class NativeImage final : public gin::Wrappable<Native
   static NativeImage* CreateFromNamedImage(gin::Arguments* args,
                                            std::string name);
   static NativeImage* CreateMenuSymbol(gin::Arguments* args, std::string name);
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   static v8::Local<v8::Promise> CreateThumbnailFromPath(
       v8::Isolate* isolate,
       const base::FilePath& path,
