--- electron/spec-main/api-browser-window-spec.ts.orig	2020-02-28 00:07:16 UTC
+++ electron/spec-main/api-browser-window-spec.ts
@@ -881,7 +881,7 @@ describe('BrowserWindow module', () => {
           w.setPosition(pos[0], pos[1])
         })
       })
-      ifdescribe(process.platform !== 'linux')(`Maximized state`, () => {
+      ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')(`Maximized state`, () => {
         it(`checks normal bounds when maximized`, (done) => {
           const bounds = w.getBounds()
           w.once('maximize', () => {
@@ -904,7 +904,7 @@ describe('BrowserWindow module', () => {
           w.maximize()
         })
       })
-      ifdescribe(process.platform !== 'linux')(`Minimized state`, () => {
+      ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')(`Minimized state`, () => {
         it(`checks normal bounds when minimized`, (done) => {
           const bounds = w.getBounds()
           w.once('minimize', () => {
@@ -1371,7 +1371,7 @@ describe('BrowserWindow module', () => {
   describe('BrowserWindow.setOpacity(opacity)', () => {
     afterEach(closeAllWindows)
 
-    ifdescribe(process.platform !== 'linux')(('Windows and Mac'), () => {
+    ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')(('Windows and Mac'), () => {
       it('make window with initial opacity', () => {
         const w = new BrowserWindow({ show: false, opacity: 0.5 })
         expect(w.getOpacity()).to.equal(0.5)
@@ -1397,7 +1397,7 @@ describe('BrowserWindow module', () => {
       })
     })
 
-    ifdescribe(process.platform === 'linux')(('Linux'), () => {
+    ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')(('Linux'), () => {
       it('sets 1 regardless of parameter', () => {
         const w = new BrowserWindow({ show: false })
         w.setOpacity(0)
@@ -2192,7 +2192,7 @@ describe('BrowserWindow module', () => {
         expect(test.version).to.equal(process.version)
         expect(test.versions).to.deep.equal(process.versions)
 
-        if (process.platform === 'linux' && test.osSandbox) {
+        if ((process.platform === 'linux' || process.platform === 'freebsd') && test.osSandbox) {
           expect(test.creationTime).to.be.null('creation time')
           expect(test.systemMemoryInfo).to.be.null('system memory info')
         } else {
@@ -2595,7 +2595,7 @@ describe('BrowserWindow module', () => {
       expect(visibilityState).to.equal('visible')
     })
 
-    ifit(!(isCI && process.platform === 'linux'))('visibilityState changes when window is minimized', async () => {
+    ifit(!(isCI && (process.platform === 'linux' || process.platform === 'freebsd')))('visibilityState changes when window is minimized', async () => {
       const w = new BrowserWindow({
         width: 100,
         height: 100,
@@ -2695,7 +2695,7 @@ describe('BrowserWindow module', () => {
     })
   })
 
-  ifdescribe(process.platform !== 'linux')('max/minimize events', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('max/minimize events', () => {
     afterEach(closeAllWindows)
     it('emits an event when window is maximized', (done) => {
       const w = new BrowserWindow({show: false})
@@ -3195,7 +3195,7 @@ describe('BrowserWindow module', () => {
     })
   })
 
-  ifdescribe(process.platform !== 'linux')('window states (excluding Linux)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('window states (excluding Linux)', () => {
     // Not implemented on Linux.
     afterEach(closeAllWindows)
 
