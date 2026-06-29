--- swiftpm/Sources/Basics/Triple+Basics.swift.orig	2024-06-05 06:47:24 UTC
+++ swiftpm/Sources/Basics/Triple+Basics.swift
@@ -136,7 +136,7 @@ extension Triple {
         switch os {
         case _ where isDarwin():
             return ".dylib"
-        case .linux, .openbsd:
+        case .linux, .openbsd, .freebsd:
             return ".so"
         case .win32:
             return ".dll"
@@ -155,7 +155,7 @@ extension Triple {
         switch os {
         case _ where isDarwin():
             return ""
-        case .linux, .openbsd:
+        case .linux, .openbsd, .freebsd:
             return ""
         case .wasi:
             return ".wasm"
