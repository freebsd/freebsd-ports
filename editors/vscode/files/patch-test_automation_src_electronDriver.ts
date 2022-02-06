--- test/automation/src/electronDriver.ts.orig	2022-02-02 16:57:24 UTC
+++ test/automation/src/electronDriver.ts
@@ -42,7 +42,7 @@ export async function launch(options: LaunchOptions): 
 		'--driver', driverIPCHandle
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		args.push('--disable-gpu'); // Linux has trouble in VMs to render properly with GPU enabled
 	}
 
@@ -157,7 +157,7 @@ function getDevElectronPath(): string {
 	switch (process.platform) {
 		case 'darwin':
 			return path.join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', 'Electron');
-		case 'linux':
+		case 'linux': case 'freebsd':
 			return path.join(buildPath, 'electron', `${product.applicationName}`);
 		case 'win32':
 			return path.join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -170,7 +170,7 @@ function getBuildElectronPath(root: string): string {
 	switch (process.platform) {
 		case 'darwin':
 			return path.join(root, 'Contents', 'MacOS', 'Electron');
-		case 'linux': {
+		case 'linux': case 'freebsd': {
 			const product = require(path.join(root, 'resources', 'app', 'product.json'));
 			return path.join(root, product.applicationName);
 		}
