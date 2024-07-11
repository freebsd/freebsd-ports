--- electron/shell/common/gin_converters/std_converter.h.orig	2023-08-14 18:19:06 UTC
+++ electron/shell/common/gin_converters/std_converter.h
@@ -28,7 +28,7 @@ v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate,
       isolate, std::forward<T>(input));
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 template <>
 struct Converter<unsigned long> {  // NOLINT(runtime/int)
   static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,
