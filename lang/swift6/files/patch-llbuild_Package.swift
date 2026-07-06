--- llbuild/Package.swift.orig	2025-11-06 14:54:32 UTC
+++ llbuild/Package.swift
@@ -97,6 +97,13 @@ let package = Package(
             exclude: ["CMakeLists.txt"]
         ),
 
+        // MARK: sqlite3 as a system library
+        .systemLibrary(
+            name: "LLBSQLite3",
+            path: "lib/LLBSQLite3",
+            pkgConfig: "sqlite3"
+        ),
+
         // MARK: Components
 
         .target(
@@ -259,6 +266,7 @@ let package = Package(
             path: "lib/llvm/Support",
             linkerSettings: [
                 .linkedLibrary("m", .when(platforms: [.linux])),
+                .linkedLibrary("execinfo"),
             ] + terminfoLibraries
         ),
     ],
