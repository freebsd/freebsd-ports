--- electron/spec/api-utility-process-spec.ts.orig	2024-10-16 13:04:26 UTC
+++ electron/spec/api-utility-process-spec.ts
@@ -418,7 +418,7 @@ describe('utilityProcess module', () => {
       expect(output).to.include(result);
     });
 
-    ifit(process.platform !== 'linux')('can access exposed main process modules from the utility process', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('can access exposed main process modules from the utility process', async () => {
       const message = 'Message from utility process';
       const child = utilityProcess.fork(path.join(fixturesPath, 'expose-main-process-module.js'));
       await once(child, 'spawn');
@@ -455,7 +455,7 @@ describe('utilityProcess module', () => {
       await closeWindow(w);
     });
 
-    ifit(process.platform === 'linux')('allows executing a setuid binary with child_process', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('allows executing a setuid binary with child_process', async () => {
       const child = utilityProcess.fork(path.join(fixturesPath, 'suid.js'));
       await once(child, 'spawn');
       const [data] = await once(child, 'message');
