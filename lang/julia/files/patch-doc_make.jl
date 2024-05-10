--- doc/make.jl.orig	2024-04-30 17:45:14.000000000 +0000
+++ doc/make.jl	2024-05-10 03:22:43.203136000 +0000
@@ -5,7 +5,30 @@
 empty!(DEPOT_PATH)
 pushfirst!(DEPOT_PATH, joinpath(@__DIR__, "deps"))
 using Pkg
-Pkg.instantiate()
+# Pkg.instantiate()
+Pkg.develop([
+    PackageSpec(path="deps/packages/LazilyInitializedFields"),
+    PackageSpec(path="deps/packages/RegistryInstances"),
+    PackageSpec(path="deps/packages/AbstractTrees"),
+    PackageSpec(path="deps/packages/Documenter"),
+    PackageSpec(path="deps/packages/TranscodingStreams"),
+    PackageSpec(path="deps/packages/CodecZlib"),
+    PackageSpec(path="deps/packages/DocumenterInventoryWritingBackport"),
+    PackageSpec(path="deps/packages/Preferences"),
+    PackageSpec(path="deps/packages/JLLWrappers"),
+    PackageSpec(path="deps/packages/OpenSSL_jll"),
+    PackageSpec(path="deps/packages/Libiconv_jll"),
+    PackageSpec(path="deps/packages/Git_jll"),
+    PackageSpec(path="deps/packages/Git"),
+    PackageSpec(path="deps/packages/Expat_jll"),
+    PackageSpec(path="deps/packages/ANSIColoredPrinters"),
+    PackageSpec(path="deps/packages/PrecompileTools"),
+    PackageSpec(path="deps/packages/Parsers"),
+    PackageSpec(path="deps/packages/MarkdownAST"),
+    PackageSpec(path="deps/packages/JSON"),
+    PackageSpec(path="deps/packages/IOCapture"),
+    PackageSpec(path="deps/packages/DocStringExtensions")
+])
 
 using Documenter
 using DocumenterInventoryWritingBackport
@@ -288,6 +311,13 @@
         collapselevel = 1,
         sidebar_sitename = false,
         ansicolor = true,
+        size_threshold_ignore = [
+            "base/arrays.md",
+            "base/base.md",
+            "base/collections.md",
+            "manual/unicode-input.md",
+            "stdlib/LinearAlgebra.md",
+        ],
     )
 end
 
@@ -299,12 +329,12 @@
     doctest   = ("doctest=fix" in ARGS) ? (:fix) : ("doctest=only" in ARGS) ? (:only) : ("doctest=true" in ARGS) ? true : false,
     linkcheck = "linkcheck=true" in ARGS,
     linkcheck_ignore = ["https://bugs.kde.org/show_bug.cgi?id=136779"], # fails to load from nanosoldier?
-    strict    = true,
     checkdocs = :none,
     format    = format,
     sitename  = "The Julia Language",
     authors   = "The Julia Project",
     pages     = PAGES,
+    remotes   = nothing,
 )
 
 # Update URLs to external stdlibs (JuliaLang/julia#43199)
