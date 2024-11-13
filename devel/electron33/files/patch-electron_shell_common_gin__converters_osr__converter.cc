--- electron/shell/common/gin_converters/osr_converter.cc.orig	2024-11-11 11:25:17 UTC
+++ electron/shell/common/gin_converters/osr_converter.cc
@@ -118,7 +118,7 @@ v8::Local<v8::Value> Converter<electron::OffscreenShar
           const_cast<uintptr_t*>(&val.shared_texture_handle)),
       sizeof(val.shared_texture_handle));
   dict.Set("sharedTextureHandle", handle_buf.ToLocalChecked());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto v8_planes = base::ToVector(val.planes, [isolate](const auto& plane) {
     gin::Dictionary v8_plane(isolate, v8::Object::New(isolate));
     v8_plane.Set("stride", plane.stride);
