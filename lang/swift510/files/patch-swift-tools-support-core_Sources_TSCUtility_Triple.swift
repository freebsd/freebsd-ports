--- swift-tools-support-core/Sources/TSCUtility/Triple.swift.orig	2024-05-11 20:29:37 UTC
+++ swift-tools-support-core/Sources/TSCUtility/Triple.swift
@@ -71,6 +71,7 @@ public struct Triple: Encodable, Equatable, Sendable {
         case linux
         case windows
         case wasi
+        case freebsd
         case openbsd
     }
 
@@ -252,7 +253,7 @@ extension Triple {
         switch os {
         case .darwin, .macOS:
             return ".dylib"
-        case .linux, .openbsd:
+        case .linux, .openbsd, .freebsd:
             return ".so"
         case .windows:
             return ".dll"
@@ -265,7 +266,7 @@ extension Triple {
       switch os {
       case .darwin, .macOS:
         return ""
-      case .linux, .openbsd:
+      case .linux, .openbsd, .freebsd:
         return ""
       case .wasi:
         return ".wasm"
