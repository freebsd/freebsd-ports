--- electron/spec-main/api-crash-reporter-spec.ts.orig	2021-04-20 23:32:33 UTC
+++ electron/spec-main/api-crash-reporter-spec.ts
@@ -12,7 +12,7 @@ import * as fs from 'fs';
 import * as uuid from 'uuid';
 
 const isWindowsOnArm = process.platform === 'win32' && process.arch === 'arm64';
-const isLinuxOnArm = process.platform === 'linux' && process.arch.includes('arm');
+const isLinuxOnArm = (process.platform === 'linux' && process.arch.includes('arm')) || process.platform === 'freebsd';
 
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
@@ -490,7 +490,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
         await bw.webContents.executeJavaScript('require(\'electron\').crashReporter.addExtraParameter(\'hello\', \'world\')');
         return bw.webContents.executeJavaScript('require(\'electron\').crashReporter.getParameters()');
       });
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // On Linux, 'getParameters' will also include the global parameters,
         // because breakpad doesn't support global parameters.
         expect(rendererParameters).to.have.property('hello', 'world');
@@ -554,7 +554,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
       }
     }
 
-    const processList = process.platform === 'linux' ? ['main', 'renderer', 'sandboxed-renderer']
+    const processList = (process.platform === 'linux' || process.platform === 'freebsd') ? ['main', 'renderer', 'sandboxed-renderer']
       : ['main', 'renderer', 'sandboxed-renderer', 'node'];
     for (const crashingProcess of processList) {
       describe(`when ${crashingProcess} crashes`, () => {
@@ -575,7 +575,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
           crash(crashingProcess, remotely);
           const newFiles = await newFileAppeared;
           expect(newFiles.length).to.be.greaterThan(0);
-          if (process.platform === 'linux') {
+          if (process.platform === 'linux' || process.platform === 'freebsd') {
             if (crashingProcess === 'main') {
               expect(newFiles[0]).to.match(/^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{8}-[0-9a-f]{8}\.dmp$/);
             } else {
@@ -609,7 +609,7 @@ ifdescribe(!isLinuxOnArm && !process.mas && !process.e
           crash(crashingProcess, remotely);
           const newFiles = await newFileAppeared;
           expect(newFiles.length).to.be.greaterThan(0);
-          if (process.platform === 'linux') {
+          if (process.platform === 'linux' || process.platform === 'freebsd') {
             if (crashingProcess === 'main') {
               expect(newFiles[0]).to.match(/^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{8}-[0-9a-f]{8}\.dmp$/);
             } else {
