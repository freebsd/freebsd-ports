--- swiftpm/Sources/Basics/Vendor/Triple+Platforms.swift.orig	2024-06-05 06:47:24 UTC
+++ swiftpm/Sources/Basics/Vendor/Triple+Platforms.swift
@@ -304,7 +304,7 @@ extension Triple {
 
     case .linux:
       return environment == .android ? "android" : "linux"
-    case .freeBSD:
+    case .freebsd:
       return "freebsd"
     case .openbsd:
       return "openbsd"
