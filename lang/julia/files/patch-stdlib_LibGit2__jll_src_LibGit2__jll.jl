--- stdlib/LibGit2_jll/src/LibGit2_jll.jl.orig	2023-05-09 10:56:52 UTC
+++ stdlib/LibGit2_jll/src/LibGit2_jll.jl
@@ -23,7 +23,7 @@ else
 elseif Sys.isapple()
     const libgit2 = "@rpath/libgit2.1.5.dylib"
 else
-    const libgit2 = "libgit2.so.1.5"
+    const libgit2 = "libgit2.so"
 end
 
 function __init__()
