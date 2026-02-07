--- swift/stdlib/public/Platform/Platform.swift.orig	2024-06-06 04:26:30 UTC
+++ swift/stdlib/public/Platform/Platform.swift
@@ -334,12 +334,12 @@ public var SIG_HOLD: sig_t { return unsafeBitCast(5, t
 public var SIG_IGN: sig_t { return unsafeBitCast(1, to: sig_t.self) }
 public var SIG_ERR: sig_t { return unsafeBitCast(-1, to: sig_t.self) }
 public var SIG_HOLD: sig_t { return unsafeBitCast(5, to: sig_t.self) }
-#elseif os(OpenBSD)
+#elseif os(OpenBSD) || os(FreeBSD)
 public var SIG_DFL: sig_t? { return nil }
 public var SIG_IGN: sig_t { return unsafeBitCast(1, to: sig_t.self) }
 public var SIG_ERR: sig_t { return unsafeBitCast(-1, to: sig_t.self) }
 public var SIG_HOLD: sig_t { return unsafeBitCast(3, to: sig_t.self) }
-#elseif os(Linux) || os(FreeBSD) || os(PS4) || os(Android) || os(Haiku)
+#elseif os(Linux) || os(PS4) || os(Android) || os(Haiku)
 public typealias sighandler_t = __sighandler_t
 
 public var SIG_DFL: sighandler_t? { return nil }
@@ -471,6 +471,17 @@ extension Duration {
   }
 }
 
+#endif
+
+#if os(FreeBSD)
+//===----------------------------------------------------------------------===//
+// arpa/inet.h
+//===----------------------------------------------------------------------===//
+
+@inline(__always)
+public func inet_pton(_ af: Int32, _ src: UnsafePointer<CChar>!, _ dst: UnsafeMutableRawPointer!) -> Int32 {
+  return __inet_pton(af, src, dst)
+}
 #endif
 
 //===----------------------------------------------------------------------===//
