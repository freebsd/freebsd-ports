--- build/lib/preLaunch.ts.orig	2022-02-09 21:24:27 UTC
+++ build/lib/preLaunch.ts
@@ -37,9 +37,9 @@ async function ensureNodeModules() {
 	}
 }
 
-async function getElectron() {
-	await runProcess(yarn, ['electron']);
-}
+// async function getElectron() {
+// 	await runProcess(yarn, ['electron']);
+// }
 
 async function ensureCompiled() {
 	if (!(await exists('out'))) {
@@ -49,7 +49,7 @@ async function ensureCompiled() {
 
 async function main() {
 	await ensureNodeModules();
-	await getElectron();
+	// await getElectron();
 	await ensureCompiled();
 
 	// Can't require this until after dependencies are installed
