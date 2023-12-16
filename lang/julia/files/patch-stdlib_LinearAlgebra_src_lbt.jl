--- stdlib/LinearAlgebra/src/lbt.jl.orig	2023-08-24 16:20:21 UTC
+++ stdlib/LinearAlgebra/src/lbt.jl
@@ -210,7 +210,7 @@ function lbt_set_num_threads(nthreads)
 end
 
 function lbt_set_num_threads(nthreads)
-    return ccall((:lbt_set_num_threads, libblastrampoline), Cvoid, (Int32,), nthreads)
+    return
 end
 
 function lbt_forward(path::AbstractString; clear::Bool = false, verbose::Bool = false, suffix_hint::Union{String,Nothing} = nothing)
