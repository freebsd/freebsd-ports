--- electron/script/lib/utils.js.orig	2026-07-07 02:14:44 UTC
+++ electron/script/lib/utils.js
@@ -20,7 +20,7 @@ function getElectronExec() {
       return `out/${OUT_DIR}/Electron.app/Contents/MacOS/Electron`;
     case 'win32':
       return `out/${OUT_DIR}/electron.exe`;
-    case 'linux':
+    case 'linux': case 'freebsd':
       return `out/${OUT_DIR}/electron`;
     default:
       throw new Error('Unknown platform');
