--- src/bootstrap-node.js.orig	2024-09-04 12:53:09 UTC
+++ src/bootstrap-node.js
@@ -168,7 +168,7 @@ module.exports.configurePortable = function (product) 
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 			return path.join(getApplicationPath(path), 'data');
 		}
 
