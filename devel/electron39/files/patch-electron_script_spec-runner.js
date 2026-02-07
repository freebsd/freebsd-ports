--- electron/script/spec-runner.js.orig	2025-12-03 04:41:24 UTC
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
@@ -431,7 +431,7 @@ async function installSpecModules (dir) {
     process.exit(1);
   }
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     const { status: rebuildStatus } = childProcess.spawnSync('npm', ['rebuild', 'abstract-socket'], {
       env,
       cwd: dir,
