--- hazkey-server/Sources/hazkey-server/socketManager.swift.orig	2026-02-08 10:07:38 UTC
+++ hazkey-server/Sources/hazkey-server/socketManager.swift
@@ -29,7 +29,11 @@ class SocketManager {
     func setupSocket() throws {
         unlink(socketPath)
 
+        #if os(FreeBSD)
+        serverFd = socket(AF_UNIX, SOCK_STREAM, 0)
+        #else
         serverFd = socket(AF_UNIX, Int32(SOCK_STREAM.rawValue), 0)
+        #endif
         guard serverFd != -1 else {
             throw SocketError.readFailed("Failed to create socket", errno)
         }
