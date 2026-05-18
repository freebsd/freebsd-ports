--- electron/shell/common/gin_converters/osr_converter.cc.orig	2026-03-17 08:46:52 UTC
+++ electron/shell/common/gin_converters/osr_converter.cc
@@ -12,7 +12,7 @@
 
 #include "base/containers/to_vector.h"
 #include "base/task/single_thread_task_runner.h"
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_number_conversions.h"
 #endif
 #include "shell/common/gin_converters/gfx_converter.h"
@@ -132,7 +132,7 @@ v8::Local<v8::Value> Converter<electron::OffscreenShar
       electron::Buffer::Copy(
           isolate, base::byte_span_from_ref(val.shared_texture_handle))
           .ToLocalChecked());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gin::Dictionary nativePixmap(isolate, v8::Object::New(isolate));
   auto v8_planes = base::ToVector(val.planes, [isolate](const auto& plane) {
     gin::Dictionary v8_plane(isolate, v8::Object::New(isolate));
