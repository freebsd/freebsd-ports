--- test/automation/src/electron.ts.orig	2026-05-29 07:25:37 UTC
+++ test/automation/src/electron.ts
@@ -151,6 +151,7 @@ export function getDevElectronPath(): string {
 		case 'darwin':
 			return join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', `${product.nameShort}`);
 		case 'linux':
+		case 'freebsd':
 			return join(buildPath, 'electron', `${product.applicationName}`);
 		case 'win32':
 			return join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -175,7 +176,8 @@ export function getBuildElectronPath(root: string): st
 				return join(root, 'Contents', 'MacOS', product.nameShort);
 			}
 		}
-		case 'linux': {
+		case 'linux':
+		case 'freebsd': {
 			const product = require(join(root, 'resources', 'app', 'product.json'));
 			return join(root, product.applicationName);
 		}
