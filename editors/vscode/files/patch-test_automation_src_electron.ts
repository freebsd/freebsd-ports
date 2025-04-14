--- test/automation/src/electron.ts.orig	2025-04-09 23:39:47 UTC
+++ test/automation/src/electron.ts
@@ -41,7 +41,7 @@ export async function resolveElectronConfiguration(opt
 		args.push('--verbose');
 	}
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		// --disable-dev-shm-usage: when run on docker containers where size of /dev/shm
 		// partition < 64MB which causes OOM failure for chromium compositor that uses
 		// this partition for shared memory.
@@ -103,7 +103,7 @@ export function getDevElectronPath(): string {
 	switch (process.platform) {
 		case 'darwin':
 			return join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', 'Electron');
-		case 'linux':
+		case 'linux': case 'freebsd':
 			return join(buildPath, 'electron', `${product.applicationName}`);
 		case 'win32':
 			return join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -116,7 +116,7 @@ export function getBuildElectronPath(root: string): st
 	switch (process.platform) {
 		case 'darwin':
 			return join(root, 'Contents', 'MacOS', 'Electron');
-		case 'linux': {
+		case 'linux': case 'freebsd': {
 			const product = require(join(root, 'resources', 'app', 'product.json'));
 			return join(root, product.applicationName);
 		}
