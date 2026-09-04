--- electron/script/spec-runner.js.orig	2026-09-04 00:15:46 UTC
+++ electron/script/spec-runner.js
@@ -554,7 +554,7 @@ async function runTestUsingElectron(specDir, testName,
     );
   }
   const runnerArgs = [`electron/${specDir}`, ...argsToPass, ...additionalArgs];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python3';
   }
@@ -625,7 +625,7 @@ async function installSpecModules(dir) {
     process.exit(1);
   }
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     const { status: rebuildStatus } = childProcess.spawnSync('npm', ['rebuild', 'abstract-socket'], {
       env,
       cwd: dir,
@@ -703,7 +703,7 @@ function getNativeAddonToolchainEnv() {
 // the same GCC that rejects the headers, so nothing on that host can build
 // the fixtures.
 function getNativeAddonToolchainEnv() {
-  if (args.electronVersion || process.platform !== 'linux') {
+  if (args.electronVersion || (process.platform !== 'linux' && process.platform !== 'freebsd')) {
     return {};
   }
   const outDir = utils.getOutDir();
