--- electron/spec/api-browser-window-spec.js.orig	2019-12-17 03:11:25 UTC
+++ electron/spec/api-browser-window-spec.js
@@ -1174,7 +1174,7 @@ describe('BrowserWindow module', () => {
   describe('BrowserWindow.setOpacity(opacity)', () => {
     describe('Windows and Mac', () => {
       before(function () {
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           this.skip()
         }
       })
@@ -1206,7 +1206,7 @@ describe('BrowserWindow module', () => {
 
     describe('Linux', () => {
       before(function () {
-        if (process.platform !== 'linux') {
+        if (process.platform !== 'linux' && process.platform !== 'freebsd') {
           this.skip()
         }
       })
@@ -1306,7 +1306,7 @@ describe('BrowserWindow module', () => {
 
   describe('enableLargerThanScreen" option', () => {
     before(function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip()
       }
     })
@@ -2400,7 +2400,7 @@ describe('BrowserWindow module', () => {
       w.loadFile(path.join(fixtures, 'pages', 'visibilitychange.html'))
     })
     it('visibilityState changes when window is minimized', function (done) {
-      if (isCI && process.platform === 'linux') {
+      if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
         // FIXME(alexeykuzmin): Skip the test instead of marking it as passed.
         // afterEach hook won't be run if a test is skipped dynamically.
         // If afterEach isn't run current window won't be destroyed
@@ -2833,7 +2833,7 @@ describe('BrowserWindow module', () => {
     // - `.skip()` called in the 'beforeEach' hook prevents 'afterEach'
     //     hook from being called.
     // Not implemented on Linux.
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       return
     }
 
