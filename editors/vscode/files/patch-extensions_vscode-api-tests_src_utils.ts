--- extensions/vscode-api-tests/src/utils.ts.orig	2019-12-18 06:34:54 UTC
+++ extensions/vscode-api-tests/src/utils.ts
@@ -36,7 +36,7 @@ export async function deleteFile(file: vscode.Uri): Pr
 }
 
 export function pathEquals(path1: string, path2: string): boolean {
-	if (process.platform !== 'linux') {
+	if (process.platform !== 'linux' && process.platform !== 'freebsd') {
 		path1 = path1.toLowerCase();
 		path2 = path2.toLowerCase();
 	}
