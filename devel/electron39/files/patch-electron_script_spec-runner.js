--- electron/script/spec-runner.js.orig	2025-09-27 23:16:33 UTC
+++ electron/script/spec-runner.js
@@ -359,7 +359,7 @@ async function runTestUsingElectron (specDir, testName
     argsToPass = argsToPass.filter(arg => (arg.toString().indexOf('--files') === -1 && arg.toString().indexOf('spec/') === -1));
   }
   const runnerArgs = [`electron/${specDir}`, ...argsToPass, ...additionalArgs];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python3';
   }
