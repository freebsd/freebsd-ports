--- stdlib/OpenLibm_jll/src/OpenLibm_jll.jl.orig	2026-10-25 17:06:47 UTC
+++ stdlib/OpenLibm_jll/src/OpenLibm_jll.jl
@@ -24,7 +24,7 @@ else
 elseif Sys.isapple()
     const libopenlibm = "@rpath/libopenlibm.4.dylib"
 else
-    const libopenlibm = "libopenlibm.so.4"
+    const libopenlibm = "libopenlibm.so"
 end
 
 function __init__()
