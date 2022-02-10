--- stdlib/LibGit2_jll/src/LibGit2_jll.jl.orig	2021-11-29 02:21:22 UTC
+++ stdlib/LibGit2_jll/src/LibGit2_jll.jl
@@ -23,7 +23,7 @@ if Sys.iswindows()
 elseif Sys.isapple()
     const libgit2 = "@rpath/libgit2.1.1.dylib"
 else
-    const libgit2 = "libgit2.so.1.1"
+    const libgit2 = "libgit2.so"
 end
 
 function __init__()
