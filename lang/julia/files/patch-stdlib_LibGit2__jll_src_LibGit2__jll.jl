--- stdlib/LibGit2_jll/src/LibGit2_jll.jl.orig	2022-11-21 00:23:36 UTC
+++ stdlib/LibGit2_jll/src/LibGit2_jll.jl
@@ -23,7 +23,7 @@ else
 elseif Sys.isapple()
     const libgit2 = "@rpath/libgit2.1.3.dylib"
 else
-    const libgit2 = "libgit2.so.1.3"
+    const libgit2 = "libgit2.so"
 end
 
 function __init__()
