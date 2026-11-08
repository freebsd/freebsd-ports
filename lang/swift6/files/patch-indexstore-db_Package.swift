--- indexstore-db/Package.swift.orig	2026-09-28 22:54:44 UTC
+++ indexstore-db/Package.swift
@@ -110,7 +110,8 @@ let package = Package(
 
     .testTarget(
       name: "ISDBTibsTests",
-      dependencies: ["ISDBTibs", "ISDBTestSupport"]
+      dependencies: ["ISDBTibs", "ISDBTestSupport"],
+      linkerSettings: [.linkedLibrary("execinfo", .when(platforms: [.custom("freebsd")]))]
     ),
 
     // Commandline tool for working with tibs projects.
