--- doc/make.jl.orig	2026-10-25 17:06:47 UTC
+++ doc/make.jl
@@ -28,7 +28,31 @@ Pkg.activate(documenter_project_dir)
 push!(DEPOT_PATH, abspath(Sys.BINDIR, Base.DATAROOTDIR, "julia"))
 using Pkg
 Pkg.activate(documenter_project_dir)
-Pkg.instantiate()
+# Pkg.instantiate()
+Pkg.develop([
+    PackageSpec(path="deps/packages/AbstractTrees"),
+    PackageSpec(path="deps/packages/ANSIColoredPrinters"),
+    PackageSpec(path="deps/packages/CodecZlib"),
+    PackageSpec(path="deps/packages/DocStringExtensions"),
+    PackageSpec(path="deps/packages/Documenter"),
+    PackageSpec(path="deps/packages/Expat_jll"),
+    PackageSpec(path="deps/packages/Git"),
+    PackageSpec(path="deps/packages/Git_jll"),
+    PackageSpec(path="deps/packages/Git_LFS_jll"),
+    PackageSpec(path="deps/packages/IOCapture"),
+    PackageSpec(path="deps/packages/JLLWrappers"),
+    PackageSpec(path="deps/packages/JSON"),
+    PackageSpec(path="deps/packages/LazilyInitializedFields"),
+    PackageSpec(path="deps/packages/Libiconv_jll"),
+    PackageSpec(path="deps/packages/MarkdownAST"),
+    PackageSpec(path="deps/packages/OpenSSH_jll"),
+    PackageSpec(path="deps/packages/Parsers"),
+    PackageSpec(path="deps/packages/PrecompileTools"),
+    PackageSpec(path="deps/packages/Preferences"),
+    PackageSpec(path="deps/packages/RegistryInstances"),
+    PackageSpec(path="deps/packages/StructUtils"),
+    PackageSpec(path="deps/packages/TranscodingStreams")
+])
 
 if "deps" in ARGS
     exit()
