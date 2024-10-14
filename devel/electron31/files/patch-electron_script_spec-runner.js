--- electron/script/spec-runner.js.orig	2024-10-09 13:53:12 UTC
+++ electron/script/spec-runner.js
@@ -165,7 +165,7 @@ async function runTestUsingElectron (specDir, testName
     exe = path.resolve(BASE, utils.getElectronExec());
   }
   const runnerArgs = [`electron/${specDir}`, ...unknownArgs.slice(2)];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python3';
   }
