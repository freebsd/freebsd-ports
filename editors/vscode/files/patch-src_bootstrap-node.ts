--- src/bootstrap-node.ts.orig	2025-02-10 13:07:56 UTC
+++ src/bootstrap-node.ts
@@ -152,7 +152,7 @@ export function configurePortable(product: Partial<IPr
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 			return path.join(getApplicationPath(), 'data');
 		}
 
