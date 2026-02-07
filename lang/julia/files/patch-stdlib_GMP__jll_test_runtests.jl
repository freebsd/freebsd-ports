--- stdlib/GMP_jll/test/runtests.jl.orig	2024-08-27 21:19:31 UTC
+++ stdlib/GMP_jll/test/runtests.jl
@@ -4,5 +4,5 @@ using Test, Libdl, GMP_jll
 
 @testset "GMP_jll" begin
     vn = VersionNumber(unsafe_string(unsafe_load(cglobal((:__gmp_version, libgmp), Ptr{Cchar}))))
-    @test vn == v"6.2.1"
+    @test vn == v"%%GMP_VER%%"
 end
