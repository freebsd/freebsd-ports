--- swiftpm/Sources/Basics/DispatchTimeInterval+Extensions.swift.orig	2024-06-05 06:47:24 UTC
+++ swiftpm/Sources/Basics/DispatchTimeInterval+Extensions.swift
@@ -95,7 +95,7 @@ extension DispatchTimeInterval {
 }
 
 // remove when available to all platforms
-#if os(Linux) || os(Windows) || os(Android) || os(OpenBSD)
+#if os(Linux) || os(Windows) || os(Android) || os(OpenBSD) || os(FreeBSD)
 extension DispatchTime {
     public func distance(to: DispatchTime) -> DispatchTimeInterval {
         let final = to.uptimeNanoseconds
