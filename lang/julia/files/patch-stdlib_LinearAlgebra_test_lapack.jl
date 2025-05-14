--- stdlib/LinearAlgebra/test/lapack.jl.orig	2024-08-27 21:19:31 UTC
+++ stdlib/LinearAlgebra/test/lapack.jl
@@ -725,7 +725,7 @@ a = zeros(2,0), zeros(0)
 @testset "issue #49489" begin
     A = randn(23,23)
     b = randn(23)
-    ipiv = collect(1:20)
+    ipiv = collect(BlasInt(1):BlasInt(20))
     @test_throws DimensionMismatch LinearAlgebra.LAPACK.getrs!('N', A, ipiv, b)
 end
 
