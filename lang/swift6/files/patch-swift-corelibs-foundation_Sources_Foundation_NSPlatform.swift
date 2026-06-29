--- swift-corelibs-foundation/Sources/Foundation/NSPlatform.swift.orig	2024-05-31 00:46:27 UTC
+++ swift-corelibs-foundation/Sources/Foundation/NSPlatform.swift
@@ -9,7 +9,7 @@ fileprivate let _NSPageSize = Int(vm_page_size)
 
 #if os(macOS) || os(iOS)
 fileprivate let _NSPageSize = Int(vm_page_size)
-#elseif os(Linux) || os(Android) || os(OpenBSD)
+#elseif os(Linux) || os(Android) || os(OpenBSD) || os(FreeBSD)
 fileprivate let _NSPageSize = Int(getpagesize())
 #elseif os(Windows)
 import WinSDK
