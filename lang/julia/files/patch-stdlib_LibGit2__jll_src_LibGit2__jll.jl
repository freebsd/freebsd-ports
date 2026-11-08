--- stdlib/LibGit2_jll/src/LibGit2_jll.jl.orig	2026-10-25 17:06:47 UTC
+++ stdlib/LibGit2_jll/src/LibGit2_jll.jl
@@ -29,7 +29,7 @@ else
 elseif Sys.isapple()
     const libgit2 = "@rpath/libgit2.1.9.dylib"
 else
-    const libgit2 = "libgit2.so.1.9"
+    const libgit2 = "libgit2.so"
 end
 
 function __init__()
