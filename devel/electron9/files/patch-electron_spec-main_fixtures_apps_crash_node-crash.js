--- electron/spec-main/fixtures/apps/crash/node-crash.js.orig	2021-01-12 00:18:11 UTC
+++ electron/spec-main/fixtures/apps/crash/node-crash.js
@@ -1,4 +1,4 @@
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   process.crashReporter.start({
     submitURL: process.argv[2],
     productName: 'Zombies',
