--- electron/spec/api-crash-reporter-spec.js.orig	2019-12-13 19:48:14 UTC
+++ electron/spec/api-crash-reporter-spec.js
@@ -19,7 +19,7 @@ describe('crashReporter module', () => {
   if (process.mas || process.env.DISABLE_CRASH_REPORTER_TESTS) return
 
   // TODO(alexeykuzmin): [Ch66] Fails. Fix it and enable back.
-  if (process.platform === 'linux') return
+  if (process.platform === 'linux' || process.platform === 'freebsd') return
 
   let originalTempDirectory = null
   let tempDirectory = null
@@ -90,7 +90,7 @@ describe('crashReporter module', () => {
         let dumpFile
         let crashesDir = crashReporter.getCrashesDirectory()
         const existingDumpFiles = new Set()
-        if (process.platform !== 'linux') {
+        if (process.platform !== 'linux' && process.platform !== 'freebsd') {
           // crashpad puts the dump files in the "completed" subdirectory
           if (process.platform === 'darwin') {
             crashesDir = path.join(crashesDir, 'completed')
@@ -101,7 +101,7 @@ describe('crashReporter module', () => {
         }
         const testDone = (uploaded) => {
           if (uploaded) return done(new Error('Uploaded crash report'))
-          if (process.platform !== 'linux') crashReporter.setUploadToServer(true)
+          if (process.platform !== 'linux' && process.platform !== 'freebsd') crashReporter.setUploadToServer(true)
           expect(fs.existsSync(dumpFile)).to.be.true()
           done()
         }
@@ -151,7 +151,7 @@ describe('crashReporter module', () => {
       })
 
       it('should send minidump with updated extra parameters when node processes crash', function (done) {
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           // FIXME(alexeykuzmin): Skip the test.
           // this.skip()
           return
@@ -305,7 +305,7 @@ describe('crashReporter module', () => {
       expect(() => require('electron').crashReporter.getUploadToServer()).to.throw()
     })
     it('returns true when uploadToServer is set to true', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -319,7 +319,7 @@ describe('crashReporter module', () => {
       expect(crashReporter.getUploadToServer()).to.be.true()
     })
     it('returns false when uploadToServer is set to false', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -340,7 +340,7 @@ describe('crashReporter module', () => {
       expect(() => require('electron').crashReporter.setUploadToServer('arg')).to.throw()
     })
     it('sets uploadToServer false when called with false', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -355,7 +355,7 @@ describe('crashReporter module', () => {
       expect(crashReporter.getUploadToServer()).to.be.false()
     })
     it('sets uploadToServer true when called with true', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -382,7 +382,7 @@ describe('crashReporter module', () => {
       expect(parameters).to.be.an('object')
     })
     it('adds a parameter to current parameters', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -397,7 +397,7 @@ describe('crashReporter module', () => {
       expect(crashReporter.getParameters()).to.have.a.property('hello')
     })
     it('removes a parameter from current parameters', function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -490,7 +490,7 @@ const startServer = ({ callback, processType, done, pr
   server.listen(port, '127.0.0.1', () => {
     port = server.address().port
     remote.process.port = port
-    if (process.platform !== 'linux') {
+    if (process.platform !== 'linux' && process.platform !== 'freebsd') {
       crashReporter.start({
         companyName: 'Umbrella Corporation',
         submitURL: 'http://127.0.0.1:' + port
