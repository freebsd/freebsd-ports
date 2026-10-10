--- src/swift/Source.swift.orig	2026-05-01 02:25:26 UTC
+++ src/swift/Source.swift
@@ -116,7 +116,7 @@ extension DispatchSource {
 	}
 #endif
 
-#if !os(Linux) && !os(Android) && !os(Windows)
+#if !os(Linux) && !os(Android) && !os(Windows) && !os(FreeBSD)
 	public struct ProcessEvent : OptionSet, RawRepresentable {
 		public let rawValue: UInt
 		public init(rawValue: UInt) { self.rawValue = rawValue }
@@ -186,7 +186,7 @@ extension DispatchSource {
 	}
 #endif
 
-#if !os(Linux) && !os(Android) && !os(Windows)
+#if !os(Linux) && !os(Android) && !os(Windows) && !os(FreeBSD)
 	public class func makeProcessSource(identifier: pid_t, eventMask: ProcessEvent, queue: DispatchQueue? = nil) -> DispatchSourceProcess {
 		let source = dispatch_source_create(_swift_dispatch_source_type_PROC(), UInt(identifier), eventMask.rawValue, queue?.__wrapped)
 		return DispatchSource(source: source) as DispatchSourceProcess
@@ -302,7 +302,7 @@ extension DispatchSourceMemoryPressure {
 }
 #endif
 
-#if !os(Linux) && !os(Android) && !os(Windows)
+#if !os(Linux) && !os(Android) && !os(Windows) && !os(FreeBSD)
 extension DispatchSourceProcess {
 	public var handle: pid_t {
 		return pid_t(CDispatch.dispatch_source_get_handle((self as! DispatchSource).__wrapped))
@@ -658,7 +658,7 @@ extension DispatchSourceTimer {
 	}
 }
 
-#if !os(Linux) && !os(Android) && !os(Windows) && !os(OpenBSD)
+#if !os(Linux) && !os(Android) && !os(Windows) && !os(OpenBSD) && !os(FreeBSD)
 extension DispatchSourceFileSystemObject {
 	public var handle: Int32 {
 		return Int32(dispatch_source_get_handle((self as! DispatchSource).__wrapped))
