--- electron/spec-main/api-crash-reporter-spec.ts.orig	2020-12-11 21:16:23 UTC
+++ electron/spec-main/api-crash-reporter-spec.ts
@@ -13,7 +13,7 @@ import * as uuid from 'uuid';
 import * as rimraf from 'rimraf';
 
 const isWindowsOnArm = process.platform === 'win32' && process.arch === 'arm64';
-const isLinuxOnArm = process.platform === 'linux' && process.arch.includes('arm');
+const isLinuxOnArm = (process.platform === 'linux' && process.arch.includes('arm')) || process.platform === 'freebsd';
 
 const afterTest: ((() => void) | (() => Promise<void>))[] = [];
 async function cleanup () {
@@ -55,7 +55,7 @@ function checkCrash (expectedProcessType: string, fiel
 
   // TODO(nornagon): minidumps are sometimes (not always) turning up empty on
   // 32-bit Linux.  Figure out why.
-  if (!(process.platform === 'linux' && process.arch === 'ia32')) {
+  if (!((process.platform === 'linux' || process.platform === 'freebsd') && process.arch === 'ia32')) {
     expect(fields.upload_file_minidump.length).to.be.greaterThan(0);
   }
 }
@@ -543,7 +543,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
         await bw.webContents.executeJavaScript('require(\'electron\').crashReporter.addExtraParameter(\'hello\', \'world\')');
         return bw.webContents.executeJavaScript('require(\'electron\').crashReporter.getParameters()');
       });
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // On Linux, 'getParameters' will also include the global parameters,
         // because breakpad doesn't support global parameters.
         expect(rendererParameters).to.have.property('hello', 'world');
@@ -611,7 +611,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
       }
     }
 
-    const processList = process.platform === 'linux' ? ['main', 'renderer', 'sandboxed-renderer']
+    const processList = (process.platform === 'linux' || process.platform === 'freebsd') ? ['main', 'renderer', 'sandboxed-renderer']
       : ['main', 'renderer', 'sandboxed-renderer', 'node'];
     for (const crashingProcess of processList) {
       describe(`when ${crashingProcess} crashes`, () => {
@@ -632,7 +632,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
           crash(crashingProcess, remotely);
           const newFiles = await newFileAppeared;
           expect(newFiles.length).to.be.greaterThan(0);
-          if (process.platform === 'linux') {
+          if (process.platform === 'linux' || process.platform === 'freebsd') {
             if (crashingProcess === 'main') {
               expect(newFiles[0]).to.match(/^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{8}-[0-9a-f]{8}\.dmp$/);
             } else {
@@ -666,7 +666,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
           crash(crashingProcess, remotely);
           const newFiles = await newFileAppeared;
           expect(newFiles.length).to.be.greaterThan(0);
-          if (process.platform === 'linux') {
+          if (process.platform === 'linux' || process.platform === 'freebsd') {
             if (crashingProcess === 'main') {
               expect(newFiles[0]).to.match(/^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{8}-[0-9a-f]{8}\.dmp$/);
             } else {
