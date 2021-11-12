--- test/automation/src/code.ts.orig	2021-07-14 21:51:05 UTC
+++ test/automation/src/code.ts
@@ -24,7 +24,7 @@ function getDevElectronPath(): string {
 	switch (process.platform) {
 		case 'darwin':
 			return path.join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', 'Electron');
-		case 'linux':
+		case 'linux': case 'freebsd':
 			return path.join(buildPath, 'electron', `${product.applicationName}`);
 		case 'win32':
 			return path.join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -37,7 +37,7 @@ function getBuildElectronPath(root: string): string {
 	switch (process.platform) {
 		case 'darwin':
 			return path.join(root, 'Contents', 'MacOS', 'Electron');
-		case 'linux': {
+		case 'linux': case 'freebsd': {
 			const product = require(path.join(root, 'resources', 'app', 'product.json'));
 			return path.join(root, product.applicationName);
 		}
@@ -148,7 +148,7 @@ export async function spawn(options: SpawnOptions): Pr
 		'--driver', handle
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		args.push('--disable-gpu'); // Linux has trouble in VMs to render properly with GPU enabled
 	}
 
