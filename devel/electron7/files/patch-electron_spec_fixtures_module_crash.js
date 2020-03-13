--- electron/spec/fixtures/module/crash.js.orig	2019-12-13 19:48:14 UTC
+++ electron/spec/fixtures/module/crash.js
@@ -10,7 +10,7 @@ process.crashReporter.start({
   }
 })
 
-if (process.platform !== 'linux') {
+if (process.platform !== 'linux' && process.platform !== 'freebsd') {
   process.crashReporter.addExtraParameter('newExtra', 'newExtra')
   process.crashReporter.addExtraParameter('removeExtra', 'removeExtra')
   process.crashReporter.removeExtraParameter('removeExtra')
