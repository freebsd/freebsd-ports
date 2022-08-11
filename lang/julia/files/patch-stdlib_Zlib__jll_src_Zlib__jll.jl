--- stdlib/Zlib_jll/src/Zlib_jll.jl.orig	2022-05-16 12:16:57 UTC
+++ stdlib/Zlib_jll/src/Zlib_jll.jl
@@ -22,7 +22,7 @@ if Sys.iswindows()
 elseif Sys.isapple()
     const libz = "@rpath/libz.1.dylib"
 else
-    const libz = "libz.so.1"
+    const libz = "libz.so"
 end
 
 function __init__()
