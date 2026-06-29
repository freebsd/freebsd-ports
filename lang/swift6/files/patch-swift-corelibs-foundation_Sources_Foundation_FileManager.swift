--- swift-corelibs-foundation/Sources/Foundation/FileManager.swift.orig	2024-05-31 00:46:27 UTC
+++ swift-corelibs-foundation/Sources/Foundation/FileManager.swift
@@ -389,7 +389,7 @@ open class FileManager : NSObject {
                     }
                     #if os(macOS) || os(iOS)
                         let modeT = number.uint16Value
-                    #elseif os(Linux) || os(Android) || os(Windows) || os(OpenBSD)
+                    #elseif os(Linux) || os(Android) || os(Windows) || os(OpenBSD) || os(FreeBSD)
                         let modeT = number.uint32Value
                     #endif
 #if os(Windows)
@@ -465,7 +465,7 @@ open class FileManager : NSObject {
                     flags |= flagsToSet
                     flags &= ~flagsToUnset
                 
-                    guard chflags(fsRep, flags) == 0 else {
+                    guard chflags(fsRep, UInt(flags)) == 0 else {
                         throw _NSErrorWithErrno(errno, reading: false, path: path)
                     }
                 #endif
@@ -872,7 +872,7 @@ open class FileManager : NSObject {
 #elseif canImport(Darwin)
         return Int(mode & ~UInt32(S_IFMT))
 #else
-        return Int(mode & ~S_IFMT)
+        return Int(mode & ~UInt32(S_IFMT))
 #endif
     }
 
