--- electron/lib/browser/rpc-server.js.orig	2019-12-02 12:19:45 UTC
+++ electron/lib/browser/rpc-server.js
@@ -482,6 +482,7 @@ const allowedClipboardMethods = (() => {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText'])
     case 'linux':
+    case 'freebsd':
       return new Set(Object.keys(clipboard))
     default:
       return new Set()
