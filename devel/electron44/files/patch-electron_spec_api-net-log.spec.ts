--- electron/spec/api-net-log.spec.ts.orig	2026-09-29 23:27:57 UTC
+++ electron/spec/api-net-log.spec.ts
@@ -129,7 +129,7 @@ describe('netLog module', () => {
     ).to.be.true('uuid present in dump');
   });
 
-  ifit(process.platform !== 'linux')(
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
     'should begin and end logging automatically when --log-net-log is passed',
     async () => {
       const appProcess = ChildProcess.spawn(process.execPath, [appPath], {
@@ -144,7 +144,7 @@ describe('netLog module', () => {
     }
   );
 
-  ifit(process.platform !== 'linux')(
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
     'should begin and end logging automatically when --log-net-log is passed, and behave correctly when .startLogging() and .stopLogging() is called',
     async () => {
       const appProcess = ChildProcess.spawn(process.execPath, [appPath], {
@@ -162,7 +162,7 @@ describe('netLog module', () => {
     }
   );
 
-  ifit(process.platform !== 'linux')(
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
     'should end logging automatically when only .startLogging() is called',
     async () => {
       const appProcess = ChildProcess.spawn(process.execPath, [appPath], {
