--- stdlib/MbedTLS_jll/test/runtests.jl.orig	2024-08-27 21:19:31 UTC
+++ stdlib/MbedTLS_jll/test/runtests.jl
@@ -6,5 +6,5 @@ using Test, Libdl, MbedTLS_jll
     vstr = zeros(UInt8, 32)
     ccall((:mbedtls_version_get_string, libmbedcrypto), Cvoid, (Ref{UInt8},), vstr)
     vn = VersionNumber(unsafe_string(pointer(vstr)))
-    @test vn == v"2.28.2"
+    @test vn == v"2.28.9"
 end
