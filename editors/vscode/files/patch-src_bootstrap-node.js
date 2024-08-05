--- src/bootstrap-node.js.orig	2024-07-31 20:26:36 UTC
+++ src/bootstrap-node.js
@@ -142,7 +142,7 @@ module.exports.configurePortable = function (product) 
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 			return path.join(getApplicationPath(path), 'data');
 		}
 
