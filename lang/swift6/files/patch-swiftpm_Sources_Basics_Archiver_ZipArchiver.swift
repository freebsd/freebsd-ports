--- swiftpm/Sources/Basics/Archiver/ZipArchiver.swift.orig	2026-09-26 11:40:58 UTC
+++ swiftpm/Sources/Basics/Archiver/ZipArchiver.swift
@@ -96,7 +96,7 @@ public struct ZipArchiver: Archiver, Cancellable {
         let process = AsyncProcess(
                 arguments: [
                     self.tar, "-c", "--format", "zip", "-f", destinationPath.pathString,
-                ] + directories.map(\.pathString),
+                ] + paths.map(\.pathString),
           workingDirectory: parent
         )
         #else
