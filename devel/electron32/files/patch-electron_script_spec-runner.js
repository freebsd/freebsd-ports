--- electron/script/spec-runner.js.orig	2025-02-26 12:22:11 UTC
+++ electron/script/spec-runner.js
@@ -200,7 +200,7 @@ async function runTestUsingElectron (specDir, testName
     exe = path.resolve(BASE, utils.getElectronExec());
   }
   const runnerArgs = [`electron/${specDir}`, ...unknownArgs.slice(2)];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python3';
   }
