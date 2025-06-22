--- swift-stress-tester/SwiftEvolve/Package.swift.orig	2023-08-11 22:27:26 UTC
+++ swift-stress-tester/SwiftEvolve/Package.swift
@@ -2,7 +2,7 @@ import PackageDescription
 
 import PackageDescription
 
-#if os(Linux)
+#if canImport(Glibc)
 import Glibc
 #else
 import Darwin.C
