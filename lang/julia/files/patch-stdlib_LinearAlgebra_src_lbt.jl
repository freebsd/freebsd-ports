--- stdlib/LinearAlgebra/src/lbt.jl.orig	2024-08-27 21:19:31 UTC
+++ stdlib/LinearAlgebra/src/lbt.jl
@@ -225,7 +225,7 @@ function lbt_set_num_threads(nthreads)
 end
 
 function lbt_set_num_threads(nthreads)
-    return ccall((:lbt_set_num_threads, libblastrampoline), Cvoid, (Int32,), nthreads)
+    return
 end
 
 function lbt_forward(path::AbstractString; clear::Bool = false, verbose::Bool = false, suffix_hint::Union{String,Nothing} = nothing)
