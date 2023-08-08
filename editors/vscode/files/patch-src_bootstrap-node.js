--- src/bootstrap-node.js.orig	2023-01-09 16:16:14 UTC
+++ src/bootstrap-node.js
@@ -124,7 +124,7 @@ exports.configurePortable = function (product) {
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 			return path.join(getApplicationPath(path), 'data');
 		}
 
