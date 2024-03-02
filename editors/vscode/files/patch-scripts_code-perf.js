--- scripts/code-perf.js.orig	2024-03-01 05:22:09 UTC
+++ scripts/code-perf.js
@@ -65,7 +65,7 @@ function getExePath(buildPath) {
 		case 'darwin':
 			relativeExePath = path.join('Contents', 'MacOS', 'Electron');
 			break;
-		case 'linux': {
+		case 'linux': case 'freebsd': {
 			const product = require(path.join(buildPath, 'resources', 'app', 'product.json'));
 			relativeExePath = product.applicationName;
 			break;
