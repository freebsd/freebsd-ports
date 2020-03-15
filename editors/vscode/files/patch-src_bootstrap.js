--- src/bootstrap.js.orig	2020-03-09 16:22:02 UTC
+++ src/bootstrap.js
@@ -243,7 +243,7 @@ exports.configurePortable = function () {
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 			return path.join(getApplicationPath(), 'data');
 		}
 
