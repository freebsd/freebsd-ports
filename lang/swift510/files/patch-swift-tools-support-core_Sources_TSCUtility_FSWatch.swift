--- swift-tools-support-core/Sources/TSCUtility/FSWatch.swift.orig	2024-05-11 20:29:37 UTC
+++ swift-tools-support-core/Sources/TSCUtility/FSWatch.swift
@@ -50,7 +50,7 @@ public class FSWatch {
         self.paths = paths
         self.latency = latency
 
-      #if os(OpenBSD)
+      #if os(OpenBSD) || os(FreeBSD)
         self._watcher = NoOpWatcher(paths: paths, latency: latency, delegate: _WatcherDelegate(block: block))
       #elseif os(Windows)
         self._watcher = RDCWatcher(paths: paths, latency: latency, delegate: _WatcherDelegate(block: block))
@@ -100,7 +100,7 @@ private protocol _FileWatcher {
     func stop()
 }
 
-#if os(OpenBSD) || (!os(macOS) && canImport(Darwin))
+#if os(OpenBSD) || os(FreeBSD) || (!os(macOS) && canImport(Darwin))
 extension FSWatch._WatcherDelegate: NoOpWatcherDelegate {}
 extension NoOpWatcher: _FileWatcher{}
 #elseif os(Windows)
@@ -118,7 +118,7 @@ extension FSEventStream: _FileWatcher{}
 
 // MARK:- inotify
 
-#if os(OpenBSD) || (!os(macOS) && canImport(Darwin))
+#if os(OpenBSD) || os(FreeBSD) || (!os(macOS) && canImport(Darwin))
 
 public protocol NoOpWatcherDelegate {
     func pathsDidReceiveEvent(_ paths: [AbsolutePath])
