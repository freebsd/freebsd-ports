--- build/lib/preLaunch.ts.orig	2022-02-05 06:44:51 UTC
+++ build/lib/preLaunch.ts
@@ -49,7 +49,7 @@ async function ensureCompiled() {
 
 async function main() {
 	await ensureNodeModules();
-	await getElectron();
+	// await getElectron();
 	await ensureCompiled();
 
 	// Can't require this until after dependencies are installed
