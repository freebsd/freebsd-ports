--- electron/spec/api-crash-reporter-spec.js.orig	2019-11-05 00:13:02 UTC
+++ electron/spec/api-crash-reporter-spec.js
@@ -16,7 +16,7 @@ describe('crashReporter module', () => {
   if (process.mas || process.env.DISABLE_CRASH_REPORTER_TESTS) return
 
   // TODO(alexeykuzmin): [Ch66] Fails. Fix it and enable back.
-  if (process.platform === 'linux') return
+  if (process.platform === 'linux' || process.platform === 'freebsd') return
 
   let originalTempDirectory = null
   let tempDirectory = null
@@ -86,7 +86,7 @@ describe('crashReporter module', () => {
         let dumpFile
         let crashesDir = crashReporter.getCrashesDirectory()
         const existingDumpFiles = new Set()
-        if (process.platform !== 'linux') {
+        if (process.platform !== 'linux' && process.platform !== 'freebsd') {
           // crashpad puts the dump files in the "completed" subdirectory
           if (process.platform === 'darwin') {
             crashesDir = path.join(crashesDir, 'completed')
@@ -97,7 +97,7 @@ describe('crashReporter module', () => {
         }
         const testDone = (uploaded) => {
           if (uploaded) return done(new Error('Uploaded crash report'))
-          if (process.platform !== 'linux') crashReporter.setUploadToServer(true)
+          if (process.platform !== 'linux' && process.platform !== 'freebsd') crashReporter.setUploadToServer(true)
           assert(fs.existsSync(dumpFile))
           done()
         }
@@ -263,7 +263,7 @@ describe('crashReporter module', () => {
       assert.throws(() => require('electron').crashReporter.getUploadToServer())
     })
     it('returns true when uploadToServer is set to true', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -277,7 +277,7 @@ describe('crashReporter module', () => {
       assert.strictEqual(crashReporter.getUploadToServer(), true)
     })
     it('returns false when uploadToServer is set to false', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -298,7 +298,7 @@ describe('crashReporter module', () => {
       assert.throws(() => require('electron').crashReporter.setUploadToServer('arg'))
     })
     it('sets uploadToServer false when called with false', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -313,7 +313,7 @@ describe('crashReporter module', () => {
       assert.strictEqual(crashReporter.getUploadToServer(), false)
     })
     it('sets uploadToServer true when called with true', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -340,7 +340,7 @@ describe('crashReporter module', () => {
       assert(typeof parameters === 'object')
     })
     it('adds a parameter to current parameters', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -355,7 +355,7 @@ describe('crashReporter module', () => {
       assert('hello' in crashReporter.getParameters())
     })
     it('removes a parameter from current parameters', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -446,7 +446,7 @@ const startServer = ({ callback, processType, done }) 
   server.listen(port, '127.0.0.1', () => {
     port = server.address().port
     remote.process.port = port
-    if (process.platform !== 'linux') {
+    if (process.platform !== 'linux' && process.platform !== 'freebsd') {
       crashReporter.start({
         companyName: 'Umbrella Corporation',
         submitURL: 'http://127.0.0.1:' + port
