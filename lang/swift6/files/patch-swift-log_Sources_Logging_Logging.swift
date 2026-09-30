--- swift-log/Sources/Logging/Logging.swift.orig	2023-12-07 18:42:43 UTC
+++ swift-log/Sources/Logging/Logging.swift
@@ -1179,7 +1179,7 @@ public struct MultiplexLogHandler: LogHandler {
     }
 }
 
-#if canImport(WASILibc) || os(Android)
+#if canImport(WASILibc) || os(Android) || os(OpenBSD)
 internal typealias CFilePointer = OpaquePointer
 #else
 internal typealias CFilePointer = UnsafeMutablePointer<FILE>
@@ -1251,8 +1251,13 @@ let systemStdout = CRT.stdout
 let systemStderr = CRT.stderr
 let systemStdout = CRT.stdout
 #elseif canImport(Glibc)
+#if os(FreeBSD) || os(OpenBSD)
+let systemStderr = Glibc.stderr
+let systemStdout = Glibc.stdout
+#else
 let systemStderr = Glibc.stderr!
 let systemStdout = Glibc.stdout!
+#endif
 #elseif canImport(Musl)
 let systemStderr = Musl.stderr!
 let systemStdout = Musl.stdout!
