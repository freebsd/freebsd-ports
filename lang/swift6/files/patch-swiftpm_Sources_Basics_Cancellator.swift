--- swiftpm/Sources/Basics/Cancellator.swift.orig	2024-06-05 06:47:24 UTC
+++ swiftpm/Sources/Basics/Cancellator.swift
@@ -79,7 +79,7 @@ public final class Cancellator: Cancellable {
 
                 // Install the default signal handler.
                 var action = sigaction()
-                #if canImport(Darwin) || os(OpenBSD)
+                #if canImport(Darwin) || os(OpenBSD) || os(FreeBSD)
                 action.__sigaction_u.__sa_handler = SIG_DFL
                 #elseif canImport(Musl)
                 action.__sa_handler.sa_handler = SIG_DFL
