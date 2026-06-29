--- swiftpm/Sources/Build/BuildPlan/BuildPlan+Product.swift.orig	2024-06-05 06:47:24 UTC
+++ swiftpm/Sources/Build/BuildPlan/BuildPlan+Product.swift
@@ -54,6 +54,8 @@ extension BuildPlan {
             if case let target as ClangTarget = target.underlyingTarget, target.isCXX {
                 if buildParameters.targetTriple.isDarwin() {
                     buildProduct.additionalFlags += ["-lc++"]
+		} else if buildParameters.targetTriple.os == .freebsd {
+                    buildProduct.additionalFlags += ["-lc++"]
                 } else if buildParameters.targetTriple.isWindows() {
                     // Don't link any C++ library.
                 } else {
