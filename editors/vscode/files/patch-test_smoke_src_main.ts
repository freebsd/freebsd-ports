--- test/smoke/src/main.ts.orig	2020-03-09 16:22:02 UTC
+++ test/smoke/src/main.ts
@@ -94,7 +94,7 @@ if (!opts.web) {
 		switch (process.platform) {
 			case 'darwin':
 				return path.join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', 'Electron');
-			case 'linux':
+			case 'linux': case 'freebsd':
 				return path.join(buildPath, 'electron', `${product.applicationName}`);
 			case 'win32':
 				return path.join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -107,7 +107,7 @@ if (!opts.web) {
 		switch (process.platform) {
 			case 'darwin':
 				return path.join(root, 'Contents', 'MacOS', 'Electron');
-			case 'linux': {
+			case 'linux': case 'freebsd': {
 				const product = require(path.join(root, 'resources', 'app', 'product.json'));
 				return path.join(root, product.applicationName);
 			}
