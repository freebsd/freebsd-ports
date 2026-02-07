--- test/automation/src/electron.ts.orig	2025-12-10 18:02:22 UTC
+++ test/automation/src/electron.ts
@@ -118,6 +118,7 @@ export function getDevElectronPath(): string {
 		case 'darwin':
 			return join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', 'Electron');
 		case 'linux':
+		case 'freebsd':
 			return join(buildPath, 'electron', `${product.applicationName}`);
 		case 'win32':
 			return join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -130,7 +131,8 @@ export function getBuildElectronPath(root: string): st
 	switch (process.platform) {
 		case 'darwin':
 			return join(root, 'Contents', 'MacOS', 'Electron');
-		case 'linux': {
+		case 'linux':
+		case 'freebsd': {
 			const product = require(join(root, 'resources', 'app', 'product.json'));
 			return join(root, product.applicationName);
 		}
