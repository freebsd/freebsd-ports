--- electron/script/lib/utils.js.orig	2019-05-14 01:53:42 UTC
+++ electron/script/lib/utils.js
@@ -9,6 +9,7 @@ function getElectronExec () {
     case 'win32':
       return `out/${OUT_DIR}/electron.exe`
     case 'linux':
+    case 'freebsd':
       return `out/${OUT_DIR}/electron`
     default:
       throw new Error('Unknown platform')
