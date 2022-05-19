--- test/automation/src/electron.ts.orig	2022-05-19 00:38:13 UTC
+++ test/automation/src/electron.ts
@@ -41,7 +41,7 @@ export async function resolveElectronConfiguration(opt
 		args.push('--verbose');
 	}
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		args.push('--disable-gpu'); // Linux has trouble in VMs to render properly with GPU enabled
 	}
 
@@ -97,7 +97,7 @@ export function getDevElectronPath(): string {
 	switch (process.platform) {
 		case 'darwin':
 			return join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', 'Electron');
-		case 'linux':
+		case 'linux': case 'freebsd':
 			return join(buildPath, 'electron', `${product.applicationName}`);
 		case 'win32':
 			return join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -110,7 +110,7 @@ export function getBuildElectronPath(root: string): st
 	switch (process.platform) {
 		case 'darwin':
 			return join(root, 'Contents', 'MacOS', 'Electron');
-		case 'linux': {
+		case 'linux': case 'freebsd': {
 			const product = require(join(root, 'resources', 'app', 'product.json'));
 			return join(root, product.applicationName);
 		}
