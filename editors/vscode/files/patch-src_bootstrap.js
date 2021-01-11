--- src/bootstrap.js.orig	2020-08-25 09:40:01 UTC
+++ src/bootstrap.js
@@ -185,7 +185,7 @@
 				return process.env['VSCODE_PORTABLE'];
 			}
 
-			if (process.platform === 'win32' || process.platform === 'linux') {
+			if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 				return path.join(getApplicationPath(), 'data');
 			}
 
