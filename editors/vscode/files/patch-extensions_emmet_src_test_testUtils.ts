--- extensions/emmet/src/test/testUtils.ts.orig	2019-12-18 06:34:11 UTC
+++ extensions/emmet/src/test/testUtils.ts
@@ -26,7 +26,7 @@ export function createRandomFile(contents = '', fileEx
 }
 
 export function pathEquals(path1: string, path2: string): boolean {
-	if (process.platform !== 'linux') {
+	if (process.platform !== 'linux' && process.platform !== 'freebsd') {
 		path1 = path1.toLowerCase();
 		path2 = path2.toLowerCase();
 	}
