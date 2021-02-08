--- test/smoke/src/main.ts.orig	2021-02-03 15:33:23 UTC
+++ test/smoke/src/main.ts
@@ -90,7 +90,7 @@ if (!opts.web) {
 		switch (process.platform) {
 			case 'darwin':
 				return path.join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', 'Electron');
-			case 'linux':
+			case 'linux': case 'freebsd':
 				return path.join(buildPath, 'electron', `${product.applicationName}`);
 			case 'win32':
 				return path.join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -103,7 +103,7 @@ if (!opts.web) {
 		switch (process.platform) {
 			case 'darwin':
 				return path.join(root, 'Contents', 'MacOS', 'Electron');
-			case 'linux': {
+			case 'linux': case 'freebsd': {
 				const product = require(path.join(root, 'resources', 'app', 'product.json'));
 				return path.join(root, product.applicationName);
 			}
