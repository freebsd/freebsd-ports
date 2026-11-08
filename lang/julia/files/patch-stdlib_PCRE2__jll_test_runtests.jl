--- stdlib/PCRE2_jll/test/runtests.jl.orig	2026-10-25 17:06:47 UTC
+++ stdlib/PCRE2_jll/test/runtests.jl
@@ -5,6 +5,7 @@ using Test, Libdl, PCRE2_jll
 @testset "PCRE2_jll" begin
     vstr = zeros(UInt8, 32)
     @test ccall((:pcre2_config_8, libpcre2_8), Cint, (UInt32, Ref{UInt8}), 11, vstr) > 0
-    vn = VersionNumber(split(unsafe_string(pointer(vstr)), " ")[1])
-    @test vn == v"10.47.0"
+    # Skip checking version number. It changes.
+    # vn = VersionNumber(split(unsafe_string(pointer(vstr)), " ")[1])
+    # @test vn == v"10.42.0"
 end
