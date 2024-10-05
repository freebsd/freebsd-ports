--- src/bootstrap-node.js.orig	2024-09-27 21:08:28 UTC
+++ src/bootstrap-node.js
@@ -169,7 +169,7 @@ module.exports.configurePortable = function (product) 
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 			return path.join(getApplicationPath(path), 'data');
 		}
 
