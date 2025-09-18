--- electron/shell/common/api/electron_api_native_image.h.orig	2025-09-02 20:56:04 UTC
+++ electron/shell/common/api/electron_api_native_image.h
@@ -82,7 +82,7 @@ class NativeImage final : public gin_helper::Deprecate
   static gin_helper::Handle<NativeImage> CreateFromNamedImage(
       gin::Arguments* args,
       std::string name);
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   static v8::Local<v8::Promise> CreateThumbnailFromPath(
       v8::Isolate* isolate,
       const base::FilePath& path,
