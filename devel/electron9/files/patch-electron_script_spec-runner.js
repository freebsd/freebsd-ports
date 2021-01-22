--- electron/script/spec-runner.js.orig	2020-05-18 21:17:08 UTC
+++ electron/script/spec-runner.js
@@ -127,7 +127,7 @@ async function runElectronTests () {
 async function runRemoteBasedElectronTests () {
   let exe = path.resolve(BASE, utils.getElectronExec());
   const runnerArgs = ['electron/spec', ...unknownArgs.slice(2)];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python';
   }
@@ -198,7 +198,7 @@ async function runNativeElectronTests () {
 async function runMainProcessElectronTests () {
   let exe = path.resolve(BASE, utils.getElectronExec());
   const runnerArgs = ['electron/spec-main', ...unknownArgs.slice(2)];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python';
   }
