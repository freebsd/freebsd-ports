--- extensions/microsoft-authentication/extension.webpack.config.js.orig	2025-12-10 18:02:22 UTC
+++ extensions/microsoft-authentication/extension.webpack.config.js
@@ -6,6 +6,7 @@ import path from 'path';
 import withDefaults, { nodePlugins } from '../shared.webpack.config.mjs';
 import CopyWebpackPlugin from 'copy-webpack-plugin';
 import path from 'path';
+import fs from 'fs';
 
 const isWindows = process.platform === 'win32';
 const isMacOS = process.platform === 'darwin';
@@ -25,6 +26,9 @@ switch (process.platform) {
 	case 'linux':
 		platformFolder = 'linux';
 		break;
+	case 'freebsd':
+		platformFolder = 'freebsd';
+		break;
 	default:
 		throw new Error(`Unsupported platform: ${process.platform}`);
 }
@@ -32,11 +36,12 @@ console.log(`Building Microsoft Authentication Extensi
 const arch = process.env.VSCODE_ARCH || process.arch;
 console.log(`Building Microsoft Authentication Extension for ${process.platform} (${arch})`);
 
+const exists = fs.globSync(`**/dist/${platformFolder}/${arch}/(lib|)msal*.(node|dll|dylib|so)`).length > 0;
 const plugins = [...nodePlugins(import.meta.dirname)];
 if (
 	(isWindows && windowsArches.includes(arch)) ||
 	isMacOS ||
-	(isLinux && linuxArches.includes(arch))
+	(isLinux && linuxArches.includes(arch) && exists)
 ) {
 	plugins.push(new CopyWebpackPlugin({
 		patterns: [
