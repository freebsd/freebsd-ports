--- src/bootstrap-node.ts.orig	2025-09-09 22:02:15 UTC
+++ src/bootstrap-node.ts
@@ -150,7 +150,7 @@ export function configurePortable(product: Partial<IPr
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 			return path.join(getApplicationPath(), 'data');
 		}
 
