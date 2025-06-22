--- swift-corelibs-foundation/Sources/Foundation/Process.swift.orig	2024-05-31 00:46:27 UTC
+++ swift-corelibs-foundation/Sources/Foundation/Process.swift
@@ -19,6 +19,8 @@ import Darwin
 import Darwin
 #endif
 
+import Glibc
+
 extension Process {
     public enum TerminationReason : Int {
         case exit
@@ -776,7 +778,7 @@ open class Process: NSObject {
         }
 
         var taskSocketPair : [Int32] = [0, 0]
-#if os(macOS) || os(iOS) || os(Android) || os(OpenBSD)
+#if os(macOS) || os(iOS) || os(Android) || os(OpenBSD) || os(FreeBSD)
         socketpair(AF_UNIX, SOCK_STREAM, 0, &taskSocketPair)
 #else
         socketpair(AF_UNIX, Int32(SOCK_STREAM.rawValue), 0, &taskSocketPair)
@@ -923,7 +925,7 @@ open class Process: NSObject {
             try _throwIfPosixError(_CFPosixSpawnFileActionsAddClose(fileActions, fd))
         }
 
-#if canImport(Darwin) || os(Android) || os(OpenBSD)
+#if canImport(Darwin) || os(Android) || os(OpenBSD) || os(FreeBSD)
         var spawnAttrs: posix_spawnattr_t? = nil
 #else
         var spawnAttrs: posix_spawnattr_t = posix_spawnattr_t()
