--- electron/spec/api-crash-reporter-spec.ts.orig	2026-05-08 13:54:01 UTC
+++ electron/spec/api-crash-reporter-spec.ts
@@ -14,7 +14,7 @@ const isWindowsOnArm = process.platform === 'win32' &&
 import { ifdescribe, ifit, defer, startRemoteControlApp, repeatedly, listen } from './lib/spec-helpers';
 
 const isWindowsOnArm = process.platform === 'win32' && process.arch === 'arm64';
-const isLinuxOnArm = process.platform === 'linux' && process.arch.includes('arm');
+const isLinuxOnArm = ((process.platform === 'linux' || process.platform === 'freebsd') && process.arch.includes('arm'));
 
 type CrashInfo = {
   prod: string;
@@ -54,7 +54,7 @@ function checkCrash(expectedProcessType: string, field
 
   // TODO(nornagon): minidumps are sometimes (not always) turning up empty on
   // 32-bit Linux.  Figure out why.
-  if (!(process.platform === 'linux' && process.arch === 'ia32')) {
+  if (!((process.platform === 'linux' || process.platform === 'freebsd') && process.arch === 'ia32')) {
     expect(fields.upload_file_minidump.length).to.be.greaterThan(0);
   }
 }
@@ -193,7 +193,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
 
       // Ensures that passing in crashpadHandlerPID flag for Linx child processes
       // does not affect child process args.
-      ifit(process.platform === 'linux')('ensure linux child process args are not modified', async () => {
+      ifit(process.platform === 'linux' || process.platform === 'freebsd')('ensure linux child process args are not modified', async () => {
         const { port, waitForCrash } = await startServer();
         let exitCode: number | null = null;
         const appPath = path.join(__dirname, 'fixtures', 'apps', 'crash');
@@ -656,7 +656,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
       }
 
       const processList =
-        process.platform === 'linux'
+        (process.platform === 'linux' || process.platform === 'freebsd')
           ? ['main', 'renderer', 'sandboxed-renderer']
           : ['main', 'renderer', 'sandboxed-renderer', 'node'];
       for (const crashingProcess of processList) {
@@ -673,7 +673,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
               return app.getPath('crashDumps');
             });
             let reportsDir = crashesDir;
-            if (process.platform === 'darwin' || process.platform === 'linux') {
+            if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd') {
               reportsDir = path.join(crashesDir, 'completed');
             } else if (process.platform === 'win32') {
               reportsDir = path.join(crashesDir, 'reports');
@@ -701,7 +701,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
             expect(remoteCrashesDir).to.equal(crashesDir);
 
             let reportsDir = crashesDir;
-            if (process.platform === 'darwin' || process.platform === 'linux') {
+            if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd') {
               reportsDir = path.join(crashesDir, 'completed');
             } else if (process.platform === 'win32') {
               reportsDir = path.join(crashesDir, 'reports');
