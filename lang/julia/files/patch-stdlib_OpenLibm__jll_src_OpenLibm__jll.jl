--- stdlib/OpenLibm_jll/src/OpenLibm_jll.jl.orig	2022-11-21 01:47:29 UTC
+++ stdlib/OpenLibm_jll/src/OpenLibm_jll.jl
@@ -22,7 +22,7 @@ else
 elseif Sys.isapple()
     const libopenlibm = "@rpath/libopenlibm.4.dylib"
 else
-    const libopenlibm = "libopenlibm.so.4"
+    const libopenlibm = "libopenlibm.so"
 end
 
 function __init__()
