--- stdlib/nghttp2_jll/test/runtests.jl.orig	2024-08-27 21:19:31 UTC
+++ stdlib/nghttp2_jll/test/runtests.jl
@@ -9,7 +9,8 @@ end
     proto_str::Cstring
 end
 
-@testset "nghttp2_jll" begin
-    info = unsafe_load(ccall((:nghttp2_version,libnghttp2), Ptr{nghttp2_info}, (Cint,), 0))
-    @test VersionNumber(unsafe_string(info.version_str)) == v"1.52.0"
-end
+# Skip version number test. It changes.
+# @testset "nghttp2_jll" begin
+#     info = unsafe_load(ccall((:nghttp2_version,libnghttp2), Ptr{nghttp2_info}, (Cint,), 0))
+#     @test VersionNumber(unsafe_string(info.version_str)) == v"1.52.0"
+# end
