--- stdlib/OpenLibm_jll/src/OpenLibm_jll.jl.orig	2021-11-25 11:01:50 UTC
+++ stdlib/OpenLibm_jll/src/OpenLibm_jll.jl
@@ -22,7 +22,7 @@ if Sys.iswindows()
 elseif Sys.isapple()
     const libopenlibm = "@rpath/libopenlibm.3.dylib"
 else
-    const libopenlibm = "libopenlibm.so.3"
+    const libopenlibm = "libopenlibm.so"
 end
 
 function __init__()
