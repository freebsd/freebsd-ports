--- llbuild/Package.swift.orig	2024-01-09 06:44:05 UTC
+++ llbuild/Package.swift
@@ -71,6 +71,13 @@ let package = Package(
             exclude: []
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
@@ -80,7 +87,7 @@ let package = Package(
         ),
         .target(
             name: "llbuildCore",
-            dependencies: ["llbuildBasic"],
+            dependencies: ["llbuildBasic", "LLBSQLite3"],
             path: "lib/Core",
             linkerSettings: [.linkedLibrary("sqlite3")]
         ),
@@ -227,6 +234,7 @@ let package = Package(
             path: "lib/llvm/Support",
             linkerSettings: [
                 .linkedLibrary("m", .when(platforms: [.linux])),
+                .linkedLibrary("execinfo"),
                 .linkedLibrary("ncurses", .when(platforms: [.linux, .macOS, .android]))]
         ),
     ],
