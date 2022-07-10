--- build/lib/preLaunch.ts.orig	2022-07-05 18:15:23 UTC
+++ build/lib/preLaunch.ts
@@ -35,9 +35,9 @@ async function ensureNodeModules() {
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
@@ -47,7 +47,7 @@ async function ensureCompiled() {
 
 async function main() {
 	await ensureNodeModules();
-	await getElectron();
+	// await getElectron();
 	await ensureCompiled();
 
 	// Can't require this until after dependencies are installed
