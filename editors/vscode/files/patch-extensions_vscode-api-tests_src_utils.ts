--- extensions/vscode-api-tests/src/utils.ts.orig	2022-02-02 16:57:24 UTC
+++ extensions/vscode-api-tests/src/utils.ts
@@ -38,7 +38,7 @@ export async function deleteFile(file: vscode.Uri): Pr
 }
 
 export function pathEquals(path1: string, path2: string): boolean {
-	if (process.platform !== 'linux') {
+	if (process.platform !== 'linux' && process.platform !== 'freebsd') {
 		path1 = path1.toLowerCase();
 		path2 = path2.toLowerCase();
 	}
