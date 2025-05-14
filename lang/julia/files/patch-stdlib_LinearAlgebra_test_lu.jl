--- stdlib/LinearAlgebra/test/lu.jl.orig	2024-08-27 21:19:31 UTC
+++ stdlib/LinearAlgebra/test/lu.jl
@@ -296,12 +296,13 @@ end
     @test_throws DomainError logdet([1 1; 1 -1])
 end
 
+# lu wants for info BlasInt not Int.
 @testset "REPL printing" begin
         bf = IOBuffer()
         show(bf, "text/plain", lu(Matrix(I, 4, 4)))
         seekstart(bf)
         @test String(take!(bf)) == """
-LinearAlgebra.LU{Float64, Matrix{Float64}, Vector{$Int}}
+LinearAlgebra.LU{Float64, Matrix{Float64}, Vector{$BlasInt}}
 L factor:
 4×4 Matrix{Float64}:
  1.0  0.0  0.0  0.0
