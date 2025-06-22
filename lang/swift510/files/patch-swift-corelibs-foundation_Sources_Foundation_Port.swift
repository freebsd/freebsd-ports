--- swift-corelibs-foundation/Sources/Foundation/Port.swift.orig	2024-05-31 00:46:27 UTC
+++ swift-corelibs-foundation/Sources/Foundation/Port.swift
@@ -83,21 +83,20 @@ public protocol PortDelegate: AnyObject {
     func handle(_ message: PortMessage)
 }
 
-#if canImport(Glibc) && !os(Android) && !os(OpenBSD)
+#if canImport(Glibc)
 import Glibc
-fileprivate let SOCK_STREAM = Int32(Glibc.SOCK_STREAM.rawValue)
-fileprivate let SOCK_DGRAM  = Int32(Glibc.SOCK_DGRAM.rawValue)
-fileprivate let IPPROTO_TCP = Int32(Glibc.IPPROTO_TCP)
-#endif
-
-#if canImport(Glibc) && os(Android) || os(OpenBSD)
-import Glibc
+#if os(Android) || os(OpenBSD) || os(FreeBSD)
 fileprivate let SOCK_STREAM = Int32(Glibc.SOCK_STREAM)
 fileprivate let SOCK_DGRAM  = Int32(Glibc.SOCK_DGRAM)
 fileprivate let IPPROTO_TCP = Int32(Glibc.IPPROTO_TCP)
 fileprivate let INADDR_ANY: in_addr_t = 0
 #if os(OpenBSD)
 fileprivate let INADDR_LOOPBACK = 0x7f000001
+#endif
+#else
+fileprivate let SOCK_STREAM = Int32(Glibc.SOCK_STREAM.rawValue)
+fileprivate let SOCK_DGRAM  = Int32(Glibc.SOCK_DGRAM.rawValue)
+fileprivate let IPPROTO_TCP = Int32(Glibc.IPPROTO_TCP)
 #endif
 #endif
 
