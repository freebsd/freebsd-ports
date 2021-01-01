--- electron/script/lib/utils.js.orig	2019-06-19 18:06:58 UTC
+++ electron/script/lib/utils.js
@@ -13,6 +13,7 @@ function getElectronExec () {
     case 'win32':
       return `out/${OUT_DIR}/electron.exe`
     case 'linux':
+    case 'freebsd':
       return `out/${OUT_DIR}/electron`
     default:
       throw new Error('Unknown platform')
