--- electron/spec/fixtures/module/crash.js.orig	2021-01-12 00:19:13 UTC
+++ electron/spec/fixtures/module/crash.js
@@ -1,4 +1,4 @@
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   process.crashReporter.start({
     submitURL: process.argv[2],
     productName: 'Zombies',
