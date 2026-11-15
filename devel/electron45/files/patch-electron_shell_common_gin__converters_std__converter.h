--- electron/shell/common/gin_converters/std_converter.h.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/common/gin_converters/std_converter.h
@@ -58,7 +58,7 @@ struct Converter<std::array<T, N>> {
   }
 };
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 template <>
 struct Converter<unsigned long> {  // NOLINT(runtime/int)
   static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,
