--- stdlib/OpenLibm_jll/src/OpenLibm_jll.jl.orig	2024-04-30 17:45:14 UTC
+++ stdlib/OpenLibm_jll/src/OpenLibm_jll.jl
@@ -22,7 +22,7 @@ else
 elseif Sys.isapple()
     const libopenlibm = "@rpath/libopenlibm.4.dylib"
 else
-    const libopenlibm = "libopenlibm.so.4"
+    const libopenlibm = "libopenlibm.so"
 end
 
 function __init__()
