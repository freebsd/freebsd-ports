--- swift-corelibs-foundation/Sources/Foundation/NSError.swift.orig	2024-05-31 00:46:27 UTC
+++ swift-corelibs-foundation/Sources/Foundation/NSError.swift
@@ -1342,7 +1342,7 @@ extension POSIXError {
     /// Bad message.
     public static var EBADMSG: POSIXError.Code { return .EBADMSG }
 
-    #if !os(OpenBSD)
+    #if !os(OpenBSD) && !os(FreeBSD)
     /// Reserved.
     public static var EMULTIHOP: POSIXError.Code { return .EMULTIHOP }
 
@@ -1362,7 +1362,7 @@ extension POSIXError {
     /// Protocol error.
     public static var EPROTO: POSIXError.Code { return .EPROTO }
 
-    #if !os(OpenBSD)
+    #if !os(OpenBSD) && !os(FreeBSD)
     /// STREAM ioctl timeout.
     public static var ETIME: POSIXError.Code { return .ETIME }
     #endif
