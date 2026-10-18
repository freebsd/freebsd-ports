--- electron/spec/api-net-log.spec.ts.orig	2026-10-15 23:46:52 UTC
+++ electron/spec/api-net-log.spec.ts
@@ -137,7 +137,7 @@ describe('netLog module', () => {
     ).toBe(true);
   });
 
-  ifit(process.platform !== 'linux')(
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
     'should begin and end logging automatically when --log-net-log is passed',
     async () => {
       const appProcess = ChildProcess.spawn(process.execPath, [appPath], {
@@ -152,7 +152,7 @@ describe('netLog module', () => {
     }
   );
 
-  ifit(process.platform !== 'linux')(
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
     'should begin and end logging automatically when --log-net-log is passed, and behave correctly when .startLogging() and .stopLogging() is called',
     async () => {
       const appProcess = ChildProcess.spawn(process.execPath, [appPath], {
@@ -170,7 +170,7 @@ describe('netLog module', () => {
     }
   );
 
-  ifit(process.platform !== 'linux')(
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
     'should end logging automatically when only .startLogging() is called',
     async () => {
       const appProcess = ChildProcess.spawn(process.execPath, [appPath], {
