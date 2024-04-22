--- electron/script/lib/utils.js.orig	2023-10-20 08:29:17 UTC
+++ electron/script/lib/utils.js
@@ -19,7 +19,7 @@ function getElectronExec () {
       return `out/${OUT_DIR}/Electron.app/Contents/MacOS/Electron`;
     case 'win32':
       return `out/${OUT_DIR}/electron.exe`;
-    case 'linux':
+    case 'linux': case 'freebsd':
       return `out/${OUT_DIR}/electron`;
     default:
       throw new Error('Unknown platform');
