--- electron/script/spec-runner.js.orig	2026-05-08 13:55:13 UTC
+++ electron/script/spec-runner.js
@@ -356,7 +356,7 @@ async function runTestUsingElectron(specDir, testName,
     );
   }
   const runnerArgs = [`electron/${specDir}`, ...argsToPass, ...additionalArgs];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python3';
   }
@@ -428,7 +428,7 @@ async function installSpecModules(dir) {
     process.exit(1);
   }
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     const { status: rebuildStatus } = childProcess.spawnSync('npm', ['rebuild', 'abstract-socket'], {
       env,
       cwd: dir,
