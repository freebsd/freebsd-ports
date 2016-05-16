--- swiftpm/Sources/PackageDescription/Package.swift.orig	2016-03-16 18:28:14 UTC
+++ swiftpm/Sources/PackageDescription/Package.swift
@@ -10,6 +10,8 @@
 
 #if os(Linux)
 import Glibc
+#elseif os(FreeBSD)
+import Glibc
 #else
 import Darwin.C
 #endif
