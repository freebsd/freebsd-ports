--- swift-tools-support-core/Sources/TSCBasic/Process.swift.orig	2024-05-11 20:29:37 UTC
+++ swift-tools-support-core/Sources/TSCBasic/Process.swift
@@ -605,7 +605,7 @@ public final class Process {
         return stdinPipe.fileHandleForWriting
     #elseif (!canImport(Darwin) || os(macOS))
         // Initialize the spawn attributes.
-      #if canImport(Darwin) || os(Android) || os(OpenBSD)
+      #if canImport(Darwin) || os(Android) || os(OpenBSD) || os(FreeBSD)
         var attributes: posix_spawnattr_t? = nil
       #else
         var attributes = posix_spawnattr_t()
@@ -650,7 +650,7 @@ public final class Process {
         posix_spawnattr_setflags(&attributes, Int16(flags))
 
         // Setup the file actions.
-      #if canImport(Darwin) || os(Android) || os(OpenBSD)
+      #if canImport(Darwin) || os(Android) || os(OpenBSD) || os(FreeBSD)
         var fileActions: posix_spawn_file_actions_t? = nil
       #else
         var fileActions = posix_spawn_file_actions_t()
@@ -666,6 +666,8 @@ public final class Process {
             if #available(macOS 10.15, *) {
                 posix_spawn_file_actions_addchdir_np(&fileActions, workingDirectory)
             }
+	  #elseif os(FreeBSD)
+            posix_spawn_file_actions_addchdir_np(&fileActions, workingDirectory)
           #elseif os(Linux)
             guard SPM_posix_spawn_file_actions_addchdir_np_supported() else {
                 throw Process.Error.workingDirectoryNotSupported
