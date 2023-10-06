--- electron/script/spec-runner.js.orig	2023-05-17 11:09:55 UTC
+++ electron/script/spec-runner.js
@@ -163,7 +163,7 @@ async function runTestUsingElectron (specDir, testName
     exe = path.resolve(BASE, utils.getElectronExec());
   }
   const runnerArgs = [`electron/${specDir}`, ...unknownArgs.slice(2)];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python3';
   }
