--- electron/spec/api-utility-process-spec.ts.orig	2023-01-24 16:58:16 UTC
+++ electron/spec/api-utility-process-spec.ts
@@ -308,7 +308,7 @@ describe('utilityProcess module', () => {
       await closeWindow(w);
     });
 
-    ifit(process.platform === 'linux')('allows executing a setuid binary with child_process', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('allows executing a setuid binary with child_process', async () => {
       const child = utilityProcess.fork(path.join(fixturesPath, 'suid.js'));
       await emittedOnce(child, 'spawn');
       const [data] = await emittedOnce(child, 'message');
