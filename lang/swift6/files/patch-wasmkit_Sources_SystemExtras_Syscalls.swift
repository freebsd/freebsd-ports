--- wasmkit/Sources/SystemExtras/Syscalls.swift.orig	2026-09-27 09:04:04 UTC
+++ wasmkit/Sources/SystemExtras/Syscalls.swift
@@ -129,7 +129,7 @@ extension CInterop {
 extension CInterop {
   #if SYSTEM_PACKAGE_DARWIN
   public typealias DirP = UnsafeMutablePointer<DIR>
-  #elseif os(Linux) || os(Android) || os(WASI)
+  #elseif os(Linux) || os(Android) || os(WASI) || os(FreeBSD)
   public typealias DirP = OpaquePointer
   #else
   #error("Unsupported Platform")
