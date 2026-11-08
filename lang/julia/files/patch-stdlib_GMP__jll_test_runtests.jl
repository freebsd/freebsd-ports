--- stdlib/GMP_jll/test/runtests.jl.orig	2026-10-25 17:06:47 UTC
+++ stdlib/GMP_jll/test/runtests.jl
@@ -4,5 +4,5 @@ using Test, Libdl, GMP_jll
 
 @testset "GMP_jll" begin
     vn = VersionNumber(unsafe_string(unsafe_load(cglobal((:__gmp_version, libgmp), Ptr{Cchar}))))
-    @test vn == v"6.3.0"
+    @test vn == v"%%GMP_VER%%"
 end
