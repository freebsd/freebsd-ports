--- src/bootstrap-node.js.orig	2021-07-14 21:51:05 UTC
+++ src/bootstrap-node.js
@@ -121,7 +121,7 @@ exports.configurePortable = function (product) {
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 			return path.join(getApplicationPath(path), 'data');
 		}
 
