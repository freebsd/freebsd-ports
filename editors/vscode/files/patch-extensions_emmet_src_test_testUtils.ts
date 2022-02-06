--- extensions/emmet/src/test/testUtils.ts.orig	2022-02-02 16:57:24 UTC
+++ extensions/emmet/src/test/testUtils.ts
@@ -31,7 +31,7 @@ export function createRandomFile(contents = '', fileEx
 }
 
 export function pathEquals(path1: string, path2: string): boolean {
-	if (process.platform !== 'linux') {
+	if (process.platform !== 'linux' && process.platform !== 'freebsd') {
 		path1 = path1.toLowerCase();
 		path2 = path2.toLowerCase();
 	}
