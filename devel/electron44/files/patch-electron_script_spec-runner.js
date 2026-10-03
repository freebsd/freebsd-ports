--- electron/script/spec-runner.js.orig	2026-09-29 23:27:57 UTC
+++ electron/script/spec-runner.js
@@ -586,7 +586,7 @@ function toVitestInvocation(exe, specDir, runnerArgs) 
   };
   let command = process.execPath;
   let commandArgs = vitestArgs;
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     // The mock D-Bus services are started once around the whole run; every
     // Electron worker inherits the bus addresses from the CLI's environment.
     commandArgs = [path.resolve(__dirname, 'dbus_mock.py'), command, ...commandArgs];
@@ -689,7 +689,7 @@ async function installSpecModules(dir) {
     process.exit(1);
   }
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     const { status: rebuildStatus } = childProcess.spawnSync('npm', ['rebuild', 'abstract-socket'], {
       env,
       cwd: dir,
@@ -767,7 +767,7 @@ function getNativeAddonToolchainEnv() {
 // the same GCC that rejects the headers, so nothing on that host can build
 // the fixtures.
 function getNativeAddonToolchainEnv() {
-  if (args.electronVersion || process.platform !== 'linux') {
+  if (args.electronVersion || (process.platform !== 'linux' && process.platform !== 'freebsd')) {
     return {};
   }
   const outDir = utils.getOutDir();
