--- stdlib/MPFR_jll/test/runtests.jl.orig	2024-08-27 21:19:31 UTC
+++ stdlib/MPFR_jll/test/runtests.jl
@@ -4,5 +4,5 @@ using Test, Libdl, MPFR_jll
 
 @testset "MPFR_jll" begin
     vn = VersionNumber(unsafe_string(ccall((:mpfr_get_version,libmpfr), Cstring, ())))
-    @test vn == v"4.2.0"
+    @test vn == v"%%MPFR_VER%%"
 end
