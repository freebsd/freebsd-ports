--- electron/spec/api-browser-window.spec.ts.orig	2026-10-07 16:24:25 UTC
+++ electron/spec/api-browser-window.spec.ts
@@ -118,7 +118,7 @@ describe('BrowserWindow module', () => {
       }).not.to.throw();
     });
 
-    ifit(process.platform === 'linux')('does not crash when setting large window icons', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('does not crash when setting large window icons', async () => {
       const appPath = path.join(fixtures, 'apps', 'xwindow-icon');
       const appProcess = childProcess.spawn(process.execPath, [appPath]);
       await once(appProcess, 'exit');
@@ -445,7 +445,7 @@ describe('BrowserWindow module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('BrowserWindow.getContentProtection', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('BrowserWindow.getContentProtection', () => {
     afterEach(closeAllWindows);
     it('can set content protection', async () => {
       const w = new BrowserWindow({ show: false });
@@ -1530,7 +1530,7 @@ describe('BrowserWindow module', () => {
 
     describe('BrowserWindow.minimize()', () => {
       // TODO(codebytere): Enable for Linux once maximize/minimize events work in CI.
-      ifit(process.platform !== 'linux')('should not be visible when the window is minimized', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should not be visible when the window is minimized', async () => {
         const minimize = once(w, 'minimize');
         w.minimize();
         await minimize;
@@ -1547,7 +1547,7 @@ describe('BrowserWindow module', () => {
       });
 
       // TODO(dsanders11): Enable for Linux once CI plays nice with these kinds of tests
-      ifit(process.platform !== 'linux')('should not restore maximized windows', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should not restore maximized windows', async () => {
         const maximize = once(w, 'maximize');
         const shown = once(w, 'show');
         w.maximize();
@@ -1644,7 +1644,7 @@ describe('BrowserWindow module', () => {
         }
       );
 
-      ifit(process.platform !== 'linux')('acquires focus status from the other windows', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('acquires focus status from the other windows', async () => {
         const w1 = new BrowserWindow({ show: false });
         const w2 = new BrowserWindow({ show: false });
         const w3 = new BrowserWindow({ show: false });
@@ -1749,7 +1749,7 @@ describe('BrowserWindow module', () => {
         expect(w.isFocused()).to.equal(false);
       });
 
-      ifit(process.platform !== 'linux')('transfers focus status to the next window', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('transfers focus status to the next window', async () => {
         const w1 = new BrowserWindow({ show: false });
         const w2 = new BrowserWindow({ show: false });
         const w3 = new BrowserWindow({ show: false });
@@ -2303,7 +2303,7 @@ describe('BrowserWindow module', () => {
         });
       });
 
-      ifdescribe(process.platform !== 'linux')('Maximized state', () => {
+      ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('Maximized state', () => {
         it('checks normal bounds when maximized', async () => {
           const bounds = w.getBounds();
           const maximize = once(w, 'maximize');
@@ -2521,7 +2521,7 @@ describe('BrowserWindow module', () => {
         });
       });
 
-      ifdescribe(process.platform !== 'linux')('Minimized state', () => {
+      ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('Minimized state', () => {
         it('checks normal bounds when minimized', async () => {
           const bounds = w.getBounds();
           const minimize = once(w, 'minimize');
@@ -3874,7 +3874,7 @@ describe('BrowserWindow module', () => {
       expect(overlayRectPreMax.height).to.equal(size);
 
       // 'maximize' event is not emitted on Linux in CI.
-      if (process.platform !== 'linux' && !w.isMaximized()) {
+      if ((process.platform !== 'linux' && process.platform !== 'freebsd') && !w.isMaximized()) {
         const maximize = once(w, 'maximize');
         w.show();
         w.maximize();
@@ -4049,7 +4049,7 @@ describe('BrowserWindow module', () => {
         expect(preMaxHeight).to.equal(size);
 
         // 'maximize' event is not emitted on Linux in CI.
-        if (process.platform !== 'linux' && !w.isMaximized()) {
+        if ((process.platform !== 'linux' && process.platform !== 'freebsd') && !w.isMaximized()) {
           const maximize = once(w, 'maximize');
           w.show();
           w.maximize();
@@ -5237,7 +5237,7 @@ describe('BrowserWindow module', () => {
         expect(test.nodeTimers).to.equal(true);
         expect(test.nodeUrl).to.equal(true);
 
-        if (process.platform === 'linux' && test.osSandbox) {
+        if ((process.platform === 'linux' || process.platform === 'freebsd') && test.osSandbox) {
           expect(test.creationTime).to.be.null('creation time');
           expect(test.systemMemoryInfo).to.be.null('system memory info');
         } else {
@@ -5753,7 +5753,7 @@ describe('BrowserWindow module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('max/minimize events', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('max/minimize events', () => {
     afterEach(closeAllWindows);
     it('emits an event when window is maximized', async () => {
       const w = new BrowserWindow({ show: false });
@@ -6029,7 +6029,7 @@ describe('BrowserWindow module', () => {
     // TODO(zcbenz):
     // This test does not run on Linux CI. See:
     // https://github.com/electron/electron/issues/28699
-    ifit(process.platform === 'linux' && !process.env.CI)(
+    ifit((process.platform === 'linux' || process.platform === 'freebsd') && !process.env.CI)(
       'should bring a minimized maximized window back to maximized state',
       async () => {
         const w = new BrowserWindow({});
@@ -6047,7 +6047,7 @@ describe('BrowserWindow module', () => {
       }
     );
 
-    ifit(process.platform !== 'linux')('should not break fullscreen state', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should not break fullscreen state', async () => {
       const w = new BrowserWindow({ show: false });
       w.show();
 
@@ -6070,7 +6070,7 @@ describe('BrowserWindow module', () => {
   });
 
   // TODO(dsanders11): Enable once maximize event works on Linux again on CI
-  ifdescribe(process.platform !== 'linux')('BrowserWindow.maximize()', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('BrowserWindow.maximize()', () => {
     afterEach(closeAllWindows);
     it('should show the window if it is not currently shown', async () => {
       const w = new BrowserWindow({ show: false });
@@ -6107,7 +6107,7 @@ describe('BrowserWindow module', () => {
 
     // TODO(dsanders11): Enable once minimize event works on Linux again.
     //                   See https://github.com/electron/electron/issues/28699
-    ifit(process.platform !== 'linux')('should not restore a minimized window', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should not restore a minimized window', async () => {
       const w = new BrowserWindow();
       const minimize = once(w, 'minimize');
       w.minimize();
@@ -6622,7 +6622,7 @@ describe('BrowserWindow module', () => {
       });
 
       // On Linux there is no "resizable" property of a window.
-      ifit(process.platform !== 'linux')('does affect maximizability when disabled and enabled', () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('does affect maximizability when disabled and enabled', () => {
         const w = new BrowserWindow({ show: false });
         expect(w.resizable).to.be.true('resizable');
 
@@ -6863,7 +6863,7 @@ describe('BrowserWindow module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('window states (excluding Linux)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('window states (excluding Linux)', () => {
     // Not implemented on Linux.
     afterEach(closeAllWindows);
 
@@ -8226,7 +8226,7 @@ describe('BrowserWindow module', () => {
   describe('"transparent" option', { tags: ['serial'] }, () => {
     afterEach(closeAllWindows);
 
-    ifit(process.platform !== 'linux')(
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')(
       'correctly returns isMaximized() when the window is maximized then minimized',
       async () => {
         const w = new BrowserWindow({
