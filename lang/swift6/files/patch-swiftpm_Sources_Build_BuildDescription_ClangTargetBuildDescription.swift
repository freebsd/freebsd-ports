--- swiftpm/Sources/Build/BuildDescription/ClangTargetBuildDescription.swift.orig	2024-06-05 06:47:24 UTC
+++ swiftpm/Sources/Build/BuildDescription/ClangTargetBuildDescription.swift
@@ -245,12 +245,12 @@ public final class ClangTargetBuildDescription {
             // 2. on Windows when compiling for any language, because of issues with the Windows SDK
             // 3. on Android when compiling for any language, because of issues with the Android SDK
             enableModules = !(buildParameters.targetTriple.isDarwin() && isCXX) && !buildParameters.targetTriple
-                .isWindows() && !buildParameters.targetTriple.isAndroid()
+                .isWindows() && !buildParameters.targetTriple.isAndroid() && buildParameters.targetTriple.os != .freebsd
         } else {
             // For version >= 5.8, we disable them when compiling for C++ regardless of platforms, see:
             // https://github.com/llvm/llvm-project/issues/55980 for clang frontend crash when module
             // enabled for C++ on c++17 standard and above.
-            enableModules = !isCXX && !buildParameters.targetTriple.isWindows() && !buildParameters.targetTriple.isAndroid()
+            enableModules = !isCXX && !buildParameters.targetTriple.isWindows() && !buildParameters.targetTriple.isAndroid() && buildParameters.targetTriple.os != .freebsd
         }
 
         if enableModules {
