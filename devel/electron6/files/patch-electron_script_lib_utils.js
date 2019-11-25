--- electron/script/lib/utils.js.orig	2019-09-11 17:30:11 UTC
+++ electron/script/lib/utils.js
@@ -15,6 +15,7 @@ function getElectronExec () {
     case 'win32':
       return `out/${OUT_DIR}/electron.exe`
     case 'linux':
+    case 'freebsd':
       return `out/${OUT_DIR}/electron`
     default:
       throw new Error('Unknown platform')
