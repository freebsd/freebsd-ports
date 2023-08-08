--- stdlib/LinearAlgebra/src/lbt.jl.orig	2022-11-23 20:37:29 UTC
+++ stdlib/LinearAlgebra/src/lbt.jl
@@ -181,7 +181,7 @@ function lbt_get_num_threads()
 end
 
 function lbt_set_num_threads(nthreads)
-    return ccall((:lbt_set_num_threads, libblastrampoline), Cvoid, (Int32,), nthreads)
+    return
 end
 
 function lbt_forward(path; clear::Bool = false, verbose::Bool = false, suffix_hint::Union{String,Nothing} = nothing)
