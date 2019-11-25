--- electron/spec/api-browser-window-spec.js.orig	2019-09-11 17:30:11 UTC
+++ electron/spec/api-browser-window-spec.js
@@ -1219,7 +1219,7 @@ describe('BrowserWindow module', () => {
   describe('BrowserWindow.setOpacity(opacity)', () => {
     describe('Windows and Mac', () => {
       before(function () {
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           this.skip()
         }
       })
@@ -1251,7 +1251,7 @@ describe('BrowserWindow module', () => {
 
     describe('Linux', () => {
       before(function () {
-        if (process.platform !== 'linux') {
+        if (process.platform !== 'linux' && process.platform !== 'freebsd') {
           this.skip()
         }
       })
@@ -1351,7 +1351,7 @@ describe('BrowserWindow module', () => {
 
   describe('enableLargerThanScreen" option', () => {
     before(function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip()
       }
     })
@@ -2028,7 +2028,7 @@ describe('BrowserWindow module', () => {
           expect(test.version).to.equal(remote.process.version)
           expect(test.versions).to.deep.equal(remote.process.versions)
 
-          if (process.platform === 'linux' && test.osSandbox) {
+          if ((process.platform === 'linux' || process.platform === 'freebsd') && test.osSandbox) {
             expect(test.creationTime).to.be.null()
             expect(test.systemMemoryInfo).to.be.null()
           } else {
@@ -2486,7 +2486,7 @@ describe('BrowserWindow module', () => {
       w.loadFile(path.join(fixtures, 'pages', 'visibilitychange.html'))
     })
     it('visibilityState changes when window is minimized', function (done) {
-      if (isCI && process.platform === 'linux') {
+      if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
         // FIXME(alexeykuzmin): Skip the test instead of marking it as passed.
         // afterEach hook won't be run if a test is skipped dynamically.
         // If afterEach isn't run current window won't be destroyed
@@ -2915,7 +2915,7 @@ describe('BrowserWindow module', () => {
     // - `.skip()` called in the 'beforeEach' hook prevents 'afterEach'
     //     hook from being called.
     // Not implemented on Linux.
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       return
     }
 
