--- src/swift/Wrapper.swift.orig	2021-09-17 04:54:52 UTC
+++ src/swift/Wrapper.swift
@@ -181,7 +181,7 @@ extension DispatchSource : DispatchSourceMachSend,
 }
 #endif
 
-#if !os(Linux) && !os(Android) && !os(Windows)
+#if !os(Linux) && !os(Android) && !os(Windows) && !os(FreeBSD)
 extension DispatchSource : DispatchSourceProcess,
 	DispatchSourceFileSystemObject {
 }
@@ -272,7 +272,7 @@ public protocol DispatchSourceMemoryPressure : Dispatc
 }
 #endif
 
-#if !os(Linux) && !os(Android) && !os(Windows)
+#if !os(Linux) && !os(Android) && !os(Windows) && !os(FreeBSD)
 public protocol DispatchSourceProcess : DispatchSourceProtocol {
 	var handle: pid_t { get }
 
@@ -302,7 +302,7 @@ public protocol DispatchSourceTimer : DispatchSourcePr
 	func scheduleRepeating(wallDeadline: DispatchWallTime, interval: Double, leeway: DispatchTimeInterval)
 }
 
-#if !os(Linux) && !os(Android) && !os(Windows)
+#if !os(Linux) && !os(Android) && !os(Windows) && !os(FreeBSD)
 public protocol DispatchSourceFileSystemObject : DispatchSourceProtocol {
 	var handle: Int32 { get }
 
