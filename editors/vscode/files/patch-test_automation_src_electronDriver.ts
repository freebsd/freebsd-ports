--- test/automation/src/electronDriver.ts.orig	2021-12-09 06:41:16 UTC
+++ test/automation/src/electronDriver.ts
@@ -39,7 +39,7 @@ export async function launch(codePath: string | undefi
 		'--driver', driverIPCHandle
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		args.push('--disable-gpu'); // Linux has trouble in VMs to render properly with GPU enabled
 	}
 
@@ -148,7 +148,7 @@ function getDevElectronPath(): string {
 	switch (process.platform) {
 		case 'darwin':
 			return path.join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', 'Electron');
-		case 'linux':
+		case 'linux': case 'freebsd':
 			return path.join(buildPath, 'electron', `${product.applicationName}`);
 		case 'win32':
 			return path.join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -161,7 +161,7 @@ function getBuildElectronPath(root: string): string {
 	switch (process.platform) {
 		case 'darwin':
 			return path.join(root, 'Contents', 'MacOS', 'Electron');
-		case 'linux': {
+		case 'linux': case 'freebsd': {
 			const product = require(path.join(root, 'resources', 'app', 'product.json'));
 			return path.join(root, product.applicationName);
 		}
