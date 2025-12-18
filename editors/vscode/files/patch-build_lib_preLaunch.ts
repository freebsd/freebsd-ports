--- build/lib/preLaunch.ts.orig	2025-12-10 18:02:22 UTC
+++ build/lib/preLaunch.ts
@@ -32,9 +32,9 @@ async function ensureNodeModules() {
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
@@ -44,7 +44,7 @@ async function main() {
 
 async function main() {
 	await ensureNodeModules();
-	await getElectron();
+	// await getElectron();
 	await ensureCompiled();
 
 	// Can't require this until after dependencies are installed
