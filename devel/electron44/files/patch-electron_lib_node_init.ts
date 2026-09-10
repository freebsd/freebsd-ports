--- electron/lib/node/init.ts.orig	2026-09-09 17:57:40 UTC
+++ electron/lib/node/init.ts
@@ -39,7 +39,7 @@ cp.fork = (modulePath, args?, options?: cp.ForkOptions
 // reported too; shell/app/node_main.cc reads these back. Every async spawn goes
 // through ChildProcess.prototype.spawn and every sync one through spawnSync,
 // both with the normalized file and envPairs.
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   const { getCrashdumpSignalFD, getCrashpadHandlerPID } = process._linkedBinding('electron_common_crashpad_support');
   const childProcess = __non_webpack_require__(
     'internal/child_process'
