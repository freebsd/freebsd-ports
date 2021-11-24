--- electron/script/spec-runner.js.orig	2021-04-20 23:32:33 UTC
+++ electron/script/spec-runner.js
@@ -126,7 +126,7 @@ async function runElectronTests () {
 async function runRemoteBasedElectronTests () {
   let exe = path.resolve(BASE, utils.getElectronExec());
   const runnerArgs = ['electron/spec', ...unknownArgs.slice(2)];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python';
   }
@@ -197,7 +197,7 @@ async function runNativeElectronTests () {
 async function runMainProcessElectronTests () {
   let exe = path.resolve(BASE, utils.getElectronExec());
   const runnerArgs = ['electron/spec-main', ...unknownArgs.slice(2)];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python';
   }
