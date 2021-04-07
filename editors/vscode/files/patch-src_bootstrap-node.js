--- src/bootstrap-node.js.orig	2021-03-30 12:04:46 UTC
+++ src/bootstrap-node.js
@@ -130,7 +130,7 @@ exports.configurePortable = function (product) {
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 			return path.join(getApplicationPath(path), 'data');
 		}
 
