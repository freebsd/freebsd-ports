--- swift-corelibs-foundation/Sources/Foundation/NSSwiftRuntime.swift.orig	2024-05-31 00:46:27 UTC
+++ swift-corelibs-foundation/Sources/Foundation/NSSwiftRuntime.swift
@@ -14,7 +14,7 @@
 // This mimics the behavior of the swift sdk overlay on Darwin
 #if os(macOS) || os(iOS) || os(tvOS) || os(watchOS)
 @_exported import Darwin
-#elseif os(Linux) || os(Android) || CYGWIN || os(OpenBSD)
+#elseif os(Linux) || os(Android) || CYGWIN || os(OpenBSD) || os(FreeBSD)
 @_exported import Glibc
 #elseif os(WASI)
 @_exported import WASILibc
