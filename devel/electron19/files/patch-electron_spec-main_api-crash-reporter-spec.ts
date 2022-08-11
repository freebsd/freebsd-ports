--- electron/spec-main/api-crash-reporter-spec.ts.orig	2021-12-03 01:46:05 UTC
+++ electron/spec-main/api-crash-reporter-spec.ts
@@ -12,7 +12,7 @@ import * as fs from 'fs';
 import * as uuid from 'uuid';
 
 const isWindowsOnArm = process.platform === 'win32' && process.arch === 'arm64';
-const isLinuxOnArm = process.platform === 'linux' && process.arch.includes('arm');
+const isLinuxOnArm = ((process.platform === 'linux' || process.platform === 'freebsd') && process.arch.includes('arm'));
 
 type CrashInfo = {
   prod: string
@@ -45,7 +45,7 @@ function checkCrash (expectedProcessType: string, fiel
 
   // TODO(nornagon): minidumps are sometimes (not always) turning up empty on
   // 32-bit Linux.  Figure out why.
-  if (!(process.platform === 'linux' && process.arch === 'ia32')) {
+  if (!((process.platform === 'linux' || process.platform === 'freebsd') && process.arch === 'ia32')) {
     expect(fields.upload_file_minidump.length).to.be.greaterThan(0);
   }
 }
@@ -279,7 +279,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
         setTimeout(() => process.crash());
       }, port);
       const crash = await waitForCrash();
-      expect(stitchLongCrashParam(crash, 'longParam')).to.have.lengthOf(160 * 127 + (process.platform === 'linux' ? 159 : 0), 'crash should have truncated longParam');
+      expect(stitchLongCrashParam(crash, 'longParam')).to.have.lengthOf(160 * 127 + ((process.platform === 'linux' || process.platform === 'freebsd') ? 159 : 0), 'crash should have truncated longParam');
     });
 
     it('should omit extra keys with names longer than the maximum', async () => {
@@ -508,7 +508,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
       }
     }
 
-    const processList = process.platform === 'linux' ? ['main', 'renderer', 'sandboxed-renderer']
+    const processList = (process.platform === 'linux' || process.platform === 'freebsd') ? ['main', 'renderer', 'sandboxed-renderer']
       : ['main', 'renderer', 'sandboxed-renderer', 'node'];
     for (const crashingProcess of processList) {
       describe(`when ${crashingProcess} crashes`, () => {
@@ -520,7 +520,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
             return app.getPath('crashDumps');
           });
           let reportsDir = crashesDir;
-          if (process.platform === 'darwin' || process.platform === 'linux') {
+          if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd') {
             reportsDir = path.join(crashesDir, 'completed');
           } else if (process.platform === 'win32') {
             reportsDir = path.join(crashesDir, 'reports');
@@ -544,7 +544,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
           expect(remoteCrashesDir).to.equal(crashesDir);
 
           let reportsDir = crashesDir;
-          if (process.platform === 'darwin' || process.platform === 'linux') {
+          if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd') {
             reportsDir = path.join(crashesDir, 'completed');
           } else if (process.platform === 'win32') {
             reportsDir = path.join(crashesDir, 'reports');
