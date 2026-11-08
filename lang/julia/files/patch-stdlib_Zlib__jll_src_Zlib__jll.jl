--- stdlib/Zlib_jll/src/Zlib_jll.jl.orig	2026-10-25 17:06:47 UTC
+++ stdlib/Zlib_jll/src/Zlib_jll.jl
@@ -21,7 +21,7 @@ else
 elseif Sys.isapple()
     const libz = "@rpath/libz.1.dylib"
 else
-    const libz = "libz.so.1"
+    const libz = "libz.so"
 end
 
 function __init__()
