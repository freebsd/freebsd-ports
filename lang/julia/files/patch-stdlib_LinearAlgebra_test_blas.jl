--- stdlib/LinearAlgebra/test/blas.jl.orig	2024-08-27 21:19:31 UTC
+++ stdlib/LinearAlgebra/test/blas.jl
@@ -730,7 +730,9 @@ end
 # Make sure we can use `Base.libblas_name`.  Avoid causing
 # https://github.com/JuliaLang/julia/issues/48427 again.
 @testset "libblas_name" begin
-    dot_sym = dlsym(dlopen(Base.libblas_name), "cblas_ddot" * (Sys.WORD_SIZE == 64 ? "64_" : ""))
+    # openblas does not implement cblas_ddot64_.
+    # dot_sym = dlsym(dlopen(Base.libblas_name), "cblas_ddot" * (Sys.WORD_SIZE == 64 ? "64_" : ""))
+    dot_sym = dlsym(dlopen(Base.libblas_name), "cblas_ddot")
     @test 23.0 === @ccall $(dot_sym)(2::Int, [2.0, 3.0]::Ref{Cdouble}, 1::Int, [4.0, 5.0]::Ref{Cdouble}, 1::Int)::Cdouble
 end
 
