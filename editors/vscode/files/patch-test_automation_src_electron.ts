--- test/automation/src/electron.ts.orig	2026-03-06 23:06:10 UTC
+++ test/automation/src/electron.ts
@@ -138,6 +138,7 @@ export function getDevElectronPath(): string {
 		case 'darwin':
 			return join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', `${product.nameShort}`);
 		case 'linux':
+		case 'freebsd':
 			return join(buildPath, 'electron', `${product.applicationName}`);
 		case 'win32':
 			return join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -162,7 +163,8 @@ export function getBuildElectronPath(root: string): st
 				return join(root, 'Contents', 'MacOS', product.nameShort);
 			}
 		}
-		case 'linux': {
+		case 'linux':
+		case 'freebsd': {
 			const product = require(join(root, 'resources', 'app', 'product.json'));
 			return join(root, product.applicationName);
 		}
