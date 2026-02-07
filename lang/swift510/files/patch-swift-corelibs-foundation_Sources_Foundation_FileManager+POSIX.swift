--- swift-corelibs-foundation/Sources/Foundation/FileManager+POSIX.swift.orig	2024-05-31 00:46:27 UTC
+++ swift-corelibs-foundation/Sources/Foundation/FileManager+POSIX.swift
@@ -70,7 +70,7 @@ extension FileManager {
             }
             urls = mountPoints(statBuf, Int(fsCount))
         }
-#elseif os(OpenBSD)
+#elseif os(OpenBSD) || os(FreeBSD)
         func mountPoints(_ statBufs: UnsafePointer<statfs>, _ fsCount: Int) -> [URL] {
             var urls: [URL] = []
 
