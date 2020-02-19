--- script/node_modules/electron-packager/targets.js.orig	1985-10-26 08:15:00 UTC
+++ script/node_modules/electron-packager/targets.js
@@ -5,9 +5,10 @@ const downloadArch = require('electron-download/lib/ar
 const semver = require('semver')
 
 const officialArchs = ['ia32', 'x64', 'armv7l', 'arm64', 'mips64el']
-const officialPlatforms = ['darwin', 'linux', 'mas', 'win32']
+const officialPlatforms = ['darwin', 'freebsd', 'linux', 'mas', 'win32']
 const officialPlatformArchCombos = {
   darwin: ['x64'],
+  freebsd: ['x64'],
   linux: ['ia32', 'x64', 'armv7l', 'arm64', 'mips64el'],
   mas: ['x64'],
   win32: ['ia32', 'x64']
@@ -21,6 +22,7 @@ const linuxArchBuildVersions = {
 // Maps to module filename for each platform (lazy-required if used)
 const osModules = {
   darwin: './mac',
+  freebsd: './linux',
   linux: './linux',
   mas: './mac', // map to darwin
   win32: './win32'
