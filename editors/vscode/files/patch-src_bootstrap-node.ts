--- src/bootstrap-node.ts.orig	2024-10-31 05:10:14 UTC
+++ src/bootstrap-node.ts
@@ -122,7 +122,7 @@ export function configurePortable(product: Partial<IPr
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 			return path.join(getApplicationPath(), 'data');
 		}
 
