--- electron/script/lib/utils.js.orig	2019-12-13 19:48:14 UTC
+++ electron/script/lib/utils.js
@@ -16,7 +16,7 @@ function getElectronExec () {
       return `out/${OUT_DIR}/Electron.app/Contents/MacOS/Electron`
     case 'win32':
       return `out/${OUT_DIR}/electron.exe`
-    case 'linux':
+    case 'linux': case 'freebsd':
       return `out/${OUT_DIR}/electron`
     default:
       throw new Error('Unknown platform')
