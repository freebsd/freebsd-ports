--- test/smoke/src/main.ts.orig	2022-02-02 16:57:24 UTC
+++ test/smoke/src/main.ts
@@ -130,7 +130,7 @@ if (!opts.web) {
 		switch (process.platform) {
 			case 'darwin':
 				return path.join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', 'Electron');
-			case 'linux':
+			case 'linux': case 'freebsd':
 				return path.join(buildPath, 'electron', `${product.applicationName}`);
 			case 'win32':
 				return path.join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -143,7 +143,7 @@ if (!opts.web) {
 		switch (process.platform) {
 			case 'darwin':
 				return path.join(root, 'Contents', 'MacOS', 'Electron');
-			case 'linux': {
+			case 'linux': case 'freebsd': {
 				const product = require(path.join(root, 'resources', 'app', 'product.json'));
 				return path.join(root, product.applicationName);
 			}
