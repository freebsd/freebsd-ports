--- src/swift/Wrapper.swift.orig	2026-05-01 02:25:26 UTC
+++ src/swift/Wrapper.swift
@@ -182,7 +182,7 @@ extension DispatchSource : DispatchSourceMachSend,
 }
 #endif
 
-#if !os(Linux) && !os(Android) && !os(Windows)
+#if !os(Linux) && !os(Android) && !os(Windows) && !os(FreeBSD)
 extension DispatchSource : DispatchSourceProcess {
 }
 #endif
@@ -277,7 +277,7 @@ public protocol DispatchSourceMemoryPressure : Dispatc
 }
 #endif
 
-#if !os(Linux) && !os(Android) && !os(Windows)
+#if !os(Linux) && !os(Android) && !os(Windows) && !os(FreeBSD)
 public protocol DispatchSourceProcess : DispatchSourceProtocol {
 	var handle: pid_t { get }
 
@@ -307,7 +307,7 @@ public protocol DispatchSourceTimer : DispatchSourcePr
 	func scheduleRepeating(wallDeadline: DispatchWallTime, interval: Double, leeway: DispatchTimeInterval)
 }
 
-#if !os(Linux) && !os(Android) && !os(Windows) && !os(OpenBSD)
+#if !os(Linux) && !os(Android) && !os(Windows) && !os(OpenBSD) && !os(FreeBSD)
 public protocol DispatchSourceFileSystemObject : DispatchSourceProtocol {
 	var handle: Int32 { get }
 
