- Handle FreeBSD platform by mapping to Linux build output path
- Make executable writable before modifying Electron fuses

--- src/node/desktop/scripts/install-fuses.mjs.orig	2025-10-20 20:09:32 UTC
+++ src/node/desktop/scripts/install-fuses.mjs
@@ -15,22 +15,28 @@ import { execSync } from 'child_process';
 
 import { flipFuses, FuseVersion, FuseV1Options } from '@electron/fuses';
 import { execSync } from 'child_process';
+import { chmodSync } from 'fs';
 import { arch, platform } from 'process';
 
 // figure out path to Electron executable
-let prefix = `out/RStudio-${platform}-${arch}`;
+// On FreeBSD we build for Linux platform, so use 'linux' in the path
+let buildPlatform = platform === 'freebsd' ? 'linux' : platform;
+let prefix = `out/RStudio-${buildPlatform}-${arch}`;
 
 let exePath = "";
 if (platform === 'darwin') {
   exePath = `${prefix}/RStudio.app/Contents/MacOS/RStudio`;
 } else if (platform === 'win32') {
   exePath = `${prefix}/RStudio.exe`;
-} else if (platform === 'linux') {
+} else if (platform === 'linux' || platform === 'freebsd') {
   exePath = `${prefix}/rstudio`;
 } else {
   throw new Error(`Unsupported platform: ${platform}`);
 }
 
+// Make the executable writable before modifying fuses
+chmodSync(exePath, 0o755);
+
 // disable potentially insecure Electron fuses
 await flipFuses(exePath, {
   version: FuseVersion.V1,
@@ -44,4 +50,3 @@ execSync(`npx @electron/fuses read --app ${exePath}`, 
   encoding: 'utf8',
   stdio: 'inherit',
 });
-
