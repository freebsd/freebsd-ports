--- electron/spec-main/api-desktop-capturer-spec.ts.orig	2021-01-22 23:55:24 UTC
+++ electron/spec-main/api-desktop-capturer-spec.ts
@@ -32,7 +32,7 @@ ifdescribe(!process.arch.includes('arm') && process.pl
   const generateSpecs = (description: string, getSources: typeof desktopCapturer.getSources) => {
     describe(description, () => {
       // TODO(nornagon): figure out why this test is failing on Linux and re-enable it.
-      ifit(process.platform !== 'linux')('should return a non-empty array of sources', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should return a non-empty array of sources', async () => {
         const sources = await getSources({ types: ['window', 'screen'] });
         expect(sources).to.be.an('array').that.is.not.empty();
       });
@@ -43,7 +43,7 @@ ifdescribe(!process.arch.includes('arm') && process.pl
       });
 
       // TODO(nornagon): figure out why this test is failing on Linux and re-enable it.
-      ifit(process.platform !== 'linux')('does not throw an error when called more than once (regression)', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('does not throw an error when called more than once (regression)', async () => {
         const sources1 = await getSources({ types: ['window', 'screen'] });
         expect(sources1).to.be.an('array').that.is.not.empty();
 
@@ -51,7 +51,7 @@ ifdescribe(!process.arch.includes('arm') && process.pl
         expect(sources2).to.be.an('array').that.is.not.empty();
       });
 
-      ifit(process.platform !== 'linux')('responds to subsequent calls of different options', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('responds to subsequent calls of different options', async () => {
         const promise1 = getSources({ types: ['window'] });
         await expect(promise1).to.eventually.be.fulfilled();
 
@@ -60,7 +60,7 @@ ifdescribe(!process.arch.includes('arm') && process.pl
       });
 
       // Linux doesn't return any window sources.
-      ifit(process.platform !== 'linux')('returns an empty display_id for window sources on Windows and Mac', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('returns an empty display_id for window sources on Windows and Mac', async () => {
         const w = new BrowserWindow({ width: 200, height: 200 });
         await w.loadURL('about:blank');
 
@@ -72,7 +72,7 @@ ifdescribe(!process.arch.includes('arm') && process.pl
         }
       });
 
-      ifit(process.platform !== 'linux')('returns display_ids matching the Screen API on Windows and Mac', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('returns display_ids matching the Screen API on Windows and Mac', async () => {
         const displays = screen.getAllDisplays();
         const sources = await getSources({ types: ['screen'] });
         expect(sources).to.be.an('array').of.length(displays.length);
@@ -87,7 +87,7 @@ ifdescribe(!process.arch.includes('arm') && process.pl
   generateSpecs('in renderer process', getSources);
   generateSpecs('in main process', desktopCapturer.getSources);
 
-  ifit(process.platform !== 'linux')('returns an empty source list if blocked by the main process', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('returns an empty source list if blocked by the main process', async () => {
     w.webContents.once('desktop-capturer-get-sources', (event) => {
       event.preventDefault();
     });
@@ -134,7 +134,7 @@ ifdescribe(!process.arch.includes('arm') && process.pl
     // TODO(julien.isorce): investigate why |sources| is empty on the linux
     // bots while it is not on my workstation, as expected, with and without
     // the --ci parameter.
-    if (process.platform === 'linux' && sources.length === 0) {
+    if ((process.platform === 'linux' || process.platform === 'freebsd') && sources.length === 0) {
       it.skip('desktopCapturer.getSources returned an empty source list');
       return;
     }
@@ -178,7 +178,7 @@ ifdescribe(!process.arch.includes('arm') && process.pl
       // TODO(julien.isorce): investigate why |sources| is empty on the linux
       // bots while it is not on my workstation, as expected, with and without
       // the --ci parameter.
-      if (process.platform === 'linux' && sources.length === 0) {
+      if ((process.platform === 'linux' || process.platform === 'freebsd') && sources.length === 0) {
         wList.forEach((w) => {
           if (w !== mainWindow) {
             w.destroy();
