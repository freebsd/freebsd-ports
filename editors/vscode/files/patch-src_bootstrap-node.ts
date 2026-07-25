--- src/bootstrap-node.ts.orig	2026-07-22 14:55:04 UTC
+++ src/bootstrap-node.ts
@@ -227,7 +227,7 @@ export function configurePortable(product: Partial<IPr
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 			return path.join(getApplicationPath(), 'data');
 		}
 
