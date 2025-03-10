--- build/lib/preLaunch.ts.orig	2024-09-27 21:08:28 UTC
+++ build/lib/preLaunch.ts
@@ -35,9 +35,9 @@ async function ensureNodeModules() {
 	}
 }
 
-async function getElectron() {
-	await runProcess(npm, ['run', 'electron']);
-}
+// async function getElectron() {
+// 	await runProcess(npm, ['run', 'electron']);
+// }
 
 async function ensureCompiled() {
 	if (!(await exists('out'))) {
@@ -47,7 +47,7 @@ async function main() {
 
 async function main() {
 	await ensureNodeModules();
-	await getElectron();
+	// await getElectron();
 	await ensureCompiled();
 
 	// Can't require this until after dependencies are installed
