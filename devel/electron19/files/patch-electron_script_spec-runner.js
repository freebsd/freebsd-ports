--- electron/script/spec-runner.js.orig	2021-11-08 18:41:28 UTC
+++ electron/script/spec-runner.js
@@ -126,7 +126,7 @@ async function runElectronTests () {
 async function runTestUsingElectron (specDir, testName) {
   let exe = path.resolve(BASE, utils.getElectronExec());
   const runnerArgs = [`electron/${specDir}`, ...unknownArgs.slice(2)];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python3';
   }
