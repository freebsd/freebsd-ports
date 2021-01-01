--- spec/main-process/atom-application.test.js.orig	2019-11-16 08:38:38 UTC
+++ spec/main-process/atom-application.test.js
@@ -1107,7 +1107,7 @@ describe('AtomApplication', function() {
   });
 
   describe('when closing the last window', function() {
-    if (process.platform === 'linux' || process.platform === 'win32') {
+    if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'win32') {
       it('quits the application', async function() {
         const [w] = await scenario.launch(parseCommandLine(['a']));
         scenario.getApplication(0).removeWindow(w);
