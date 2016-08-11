--- swiftpm/Sources/libc/libc.swift.orig	2016-03-16 18:28:14 UTC
+++ swiftpm/Sources/libc/libc.swift
@@ -10,6 +10,8 @@
 
 #if os(Linux)
 @_exported import Glibc
+#elseif os(FreeBSD)
+@_exported import Glibc
 #else
 @_exported import Darwin.C
 #endif
