--- electron/shell/common/gin_converters/osr_converter.cc.orig	2025-09-02 20:56:04 UTC
+++ electron/shell/common/gin_converters/osr_converter.cc
@@ -12,7 +12,7 @@
 #include <string>
 
 #include "base/containers/to_vector.h"
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_number_conversions.h"
 #endif
 #include "shell/common/gin_converters/gfx_converter.h"
@@ -118,7 +118,7 @@ v8::Local<v8::Value> Converter<electron::OffscreenShar
            electron::Buffer::Copy(
                isolate, base::byte_span_from_ref(val.shared_texture_handle))
                .ToLocalChecked());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto v8_planes = base::ToVector(val.planes, [isolate](const auto& plane) {
     gin::Dictionary v8_plane(isolate, v8::Object::New(isolate));
     v8_plane.Set("stride", plane.stride);
