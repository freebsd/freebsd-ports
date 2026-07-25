--- electron/script/spec-runner.js.orig	2026-07-21 15:33:01 UTC
+++ electron/script/spec-runner.js
@@ -543,7 +543,7 @@ async function runTestUsingElectron(specDir, testName,
     );
   }
   const runnerArgs = [`electron/${specDir}`, ...argsToPass, ...additionalArgs];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python3';
   }
@@ -614,7 +614,7 @@ async function installSpecModules(dir) {
     process.exit(1);
   }
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     const { status: rebuildStatus } = childProcess.spawnSync('npm', ['rebuild', 'abstract-socket'], {
       env,
       cwd: dir,
