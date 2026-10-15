--- electron/spec/api-net-log.spec.ts.orig	2026-10-13 23:40:13 UTC
+++ electron/spec/api-net-log.spec.ts
@@ -133,7 +133,7 @@ describe('netLog module', () => {
     ).to.be.true('uuid present in dump');
   });
 
-  ifit(process.platform !== 'linux')(
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
     'should begin and end logging automatically when --log-net-log is passed',
     async () => {
       const appProcess = ChildProcess.spawn(process.execPath, [appPath], {
@@ -148,7 +148,7 @@ describe('netLog module', () => {
     }
   );
 
-  ifit(process.platform !== 'linux')(
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
     'should begin and end logging automatically when --log-net-log is passed, and behave correctly when .startLogging() and .stopLogging() is called',
     async () => {
       const appProcess = ChildProcess.spawn(process.execPath, [appPath], {
@@ -166,7 +166,7 @@ describe('netLog module', () => {
     }
   );
 
-  ifit(process.platform !== 'linux')(
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
     'should end logging automatically when only .startLogging() is called',
     async () => {
       const appProcess = ChildProcess.spawn(process.execPath, [appPath], {
