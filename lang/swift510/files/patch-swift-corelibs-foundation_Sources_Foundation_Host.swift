--- swift-corelibs-foundation/Sources/Foundation/Host.swift.orig	2024-05-31 00:46:27 UTC
+++ swift-corelibs-foundation/Sources/Foundation/Host.swift
@@ -186,7 +186,7 @@ open class Host: NSObject {
                 let family = ifa_addr.pointee.sa_family
                 if family == sa_family_t(AF_INET) || family == sa_family_t(AF_INET6) {
                     let sa_len: socklen_t = socklen_t((family == sa_family_t(AF_INET6)) ? MemoryLayout<sockaddr_in6>.size : MemoryLayout<sockaddr_in>.size)
-#if os(OpenBSD)
+#if os(OpenBSD) || os(FreeBSD)
                     let hostlen = size_t(NI_MAXHOST)
 #else
                     let hostlen = socklen_t(NI_MAXHOST)
@@ -281,7 +281,7 @@ open class Host: NSObject {
             }
             var hints = addrinfo()
             hints.ai_family = PF_UNSPEC
-#if os(macOS) || os(iOS) || os(Android) || os(OpenBSD)
+#if os(macOS) || os(iOS) || os(Android) || os(OpenBSD) || os(FreeBSD)
             hints.ai_socktype = SOCK_STREAM
 #else
             hints.ai_socktype = Int32(SOCK_STREAM.rawValue)
@@ -311,7 +311,7 @@ open class Host: NSObject {
                 }
                 let sa_len: socklen_t = socklen_t((family == AF_INET6) ? MemoryLayout<sockaddr_in6>.size : MemoryLayout<sockaddr_in>.size)
                 let lookupInfo = { (content: inout [String], flags: Int32) in
-#if os(OpenBSD)
+#if os(OpenBSD) || os(FreeBSD)
                     let hostlen = size_t(NI_MAXHOST)
 #else
                     let hostlen = socklen_t(NI_MAXHOST)
