--- swift-tools-support-core/Sources/TSCUtility/InterruptHandler.swift.orig	2024-05-11 20:29:37 UTC
+++ swift-tools-support-core/Sources/TSCUtility/InterruptHandler.swift
@@ -74,7 +74,7 @@ public final class InterruptHandler {
         }
       #else
         var action = sigaction()
-      #if canImport(Darwin) || os(OpenBSD)
+      #if canImport(Darwin) || os(OpenBSD) || os(FreeBSD)
         action.__sigaction_u.__sa_handler = self.signalHandler
       #elseif os(Android)
         action.sa_handler = self.signalHandler
