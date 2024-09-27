--- electron/script/spec-runner.js.orig	2024-02-21 16:26:48 UTC
+++ electron/script/spec-runner.js
@@ -161,7 +161,7 @@ async function runTestUsingElectron (specDir, testName
     exe = path.resolve(BASE, utils.getElectronExec());
   }
   const runnerArgs = [`electron/${specDir}`, ...unknownArgs.slice(2)];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python3';
   }
