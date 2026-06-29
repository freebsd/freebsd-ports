--- swift-system/Sources/System/Internals/Constants.swift.orig	2021-12-02 19:22:32 UTC
+++ swift-system/Sources/System/Internals/Constants.swift
@@ -396,23 +396,29 @@ internal var _EMULTIHOP: CInt { EMULTIHOP }
 @_alwaysEmitIntoClient
 internal var _EMULTIHOP: CInt { EMULTIHOP }
 
+#if !os(FreeBSD)
 @_alwaysEmitIntoClient
 internal var _ENODATA: CInt { ENODATA }
+#endif
 
 @_alwaysEmitIntoClient
 internal var _ENOLINK: CInt { ENOLINK }
 
+#if !os(FreeBSD)
 @_alwaysEmitIntoClient
 internal var _ENOSR: CInt { ENOSR }
 
 @_alwaysEmitIntoClient
 internal var _ENOSTR: CInt { ENOSTR }
+#endif
 
 @_alwaysEmitIntoClient
 internal var _EPROTO: CInt { EPROTO }
 
+#if !os(FreeBSD)
 @_alwaysEmitIntoClient
 internal var _ETIME: CInt { ETIME }
+#endif
 #endif
 
 @_alwaysEmitIntoClient
