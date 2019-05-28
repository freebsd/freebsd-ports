--- electron/spec/api-crash-reporter-spec.js.orig	2019-05-14 03:49:42 UTC
+++ electron/spec/api-crash-reporter-spec.js
@@ -16,7 +16,7 @@ describe('crashReporter module', () => {
   if (process.mas || process.env.DISABLE_CRASH_REPORTER_TESTS) return
 
   // TODO(alexeykuzmin): [Ch66] Fails. Fix it and enable back.
-  if (process.platform === 'linux') return
+  if (process.platform === 'linux' || process.platform === 'freebsd') return
 
   let originalTempDirectory = null
   let tempDirectory = null
