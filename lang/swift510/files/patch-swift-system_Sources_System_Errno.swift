--- swift-system/Sources/System/Errno.swift.orig	2021-12-02 19:22:32 UTC
+++ swift-system/Sources/System/Errno.swift
@@ -1286,6 +1286,7 @@ public struct Errno: RawRepresentable, Error, Hashable
   @available(*, unavailable, renamed: "multiHop")
   public static var EMULTIHOP: Errno { multiHop }
 
+#if !os(FreeBSD)
   /// No message available.
   ///
   /// No message was available to be received by the requested operation.
@@ -1297,6 +1298,7 @@ public struct Errno: RawRepresentable, Error, Hashable
   @_alwaysEmitIntoClient
   @available(*, unavailable, renamed: "noData")
   public static var ENODATA: Errno { noData }
+#endif
 
   /// Reserved.
   ///
@@ -1310,6 +1312,7 @@ public struct Errno: RawRepresentable, Error, Hashable
   @available(*, unavailable, renamed: "noLink")
   public static var ENOLINK: Errno { noLink }
 
+#if !os(FreeBSD)
   /// Reserved.
   ///
   /// This error is reserved for future use.
@@ -1333,6 +1336,7 @@ public struct Errno: RawRepresentable, Error, Hashable
   @_alwaysEmitIntoClient
   @available(*, unavailable, renamed: "notStream")
   public static var ENOSTR: Errno { notStream }
+#endif
 
   /// Protocol error.
   ///
@@ -1348,6 +1352,7 @@ public struct Errno: RawRepresentable, Error, Hashable
   @available(*, unavailable, renamed: "protocolError")
   public static var EPROTO: Errno { protocolError }
 
+#if !os(FreeBSD)
   /// Reserved.
   ///
   /// This error is reserved for future use.
@@ -1359,6 +1364,7 @@ public struct Errno: RawRepresentable, Error, Hashable
   @_alwaysEmitIntoClient
   @available(*, unavailable, renamed: "timeout")
   public static var ETIME: Errno { timeout }
+#endif
 #endif
 
   /// Operation not supported on socket.
