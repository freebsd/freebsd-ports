--- electron/script/spec-runner.js.orig	2020-03-24 05:00:48 UTC
+++ electron/script/spec-runner.js
@@ -115,7 +115,7 @@ async function runElectronTests () {
 async function runRemoteBasedElectronTests () {
   let exe = path.resolve(BASE, utils.getElectronExec());
   const runnerArgs = ['electron/spec', ...unknownArgs.slice(2)];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python';
   }
