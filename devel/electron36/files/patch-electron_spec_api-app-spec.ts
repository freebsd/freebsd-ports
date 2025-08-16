--- electron/spec/api-app-spec.ts.orig	2025-08-14 14:48:00 UTC
+++ electron/spec/api-app-spec.ts
@@ -129,11 +129,11 @@ describe('app module', () => {
   });
 
   describe('app.getPreferredSystemLanguages()', () => {
-    ifit(process.platform !== 'linux')('should not be empty', () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should not be empty', () => {
       expect(app.getPreferredSystemLanguages().length).to.not.equal(0);
     });
 
-    ifit(process.platform === 'linux')('should be empty or contain C entry', () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('should be empty or contain C entry', () => {
       const languages = app.getPreferredSystemLanguages();
       if (languages.length) {
         expect(languages).to.not.include('C');
@@ -196,7 +196,7 @@ describe('app module', () => {
       expect(code).to.equal(123, 'exit code should be 123, if you see this please tag @MarshallOfSound');
     });
 
-    ifit(['darwin', 'linux'].includes(process.platform))('exits gracefully', async function () {
+    ifit(['darwin', 'linux', 'freebsd'].includes(process.platform))('exits gracefully', async function () {
       const electronPath = process.execPath;
       const appPath = path.join(fixturesPath, 'api', 'singleton');
       appProcess = cp.spawn(electronPath, [appPath]);
@@ -360,7 +360,7 @@ describe('app module', () => {
   });
 
   // GitHub Actions macOS-13 runners used for x64 seem to have a problem with this test.
-  ifdescribe(process.platform !== 'linux' && !isMacOSx64)('app.{add|get|clear}RecentDocument(s)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && !isMacOSx64)('app.{add|get|clear}RecentDocument(s)', () => {
     const tempFiles = [
       path.join(fixturesPath, 'foo.txt'),
       path.join(fixturesPath, 'bar.txt'),
@@ -488,7 +488,7 @@ describe('app module', () => {
   //   let w = null
 
   //   before(function () {
-  //     if (process.platform !== 'linux') {
+  //     if (process.platform !== 'linux' && process.platform !== 'freebsd') {
   //       this.skip()
   //     }
   //   })
@@ -595,7 +595,7 @@ describe('app module', () => {
   describe('app.badgeCount', () => {
     const platformIsNotSupported =
       (process.platform === 'win32') ||
-      (process.platform === 'linux' && !app.isUnityRunning());
+      (process.platform === 'linux' && !app.isUnityRunning()) || (process.platform === 'freebsd');
 
     const expectedBadgeCount = 42;
 
@@ -639,7 +639,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux' && !process.mas && (process.platform !== 'darwin' || process.arch === 'arm64'))('app.get/setLoginItemSettings API', function () {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && !process.mas && (process.platform !== 'darwin' || process.arch === 'arm64'))('app.get/setLoginItemSettings API', function () {
     const isMac = process.platform === 'darwin';
     const isWin = process.platform === 'win32';
 
@@ -1019,7 +1019,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('accessibilitySupportEnabled property', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('accessibilitySupportEnabled property', () => {
     it('is mutable', () => {
       const values = [false, true, false];
       const setters: Array<(arg: boolean) => void> = [
@@ -1219,7 +1219,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('select-client-certificate event', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('select-client-certificate event', () => {
     let w: BrowserWindow;
 
     before(function () {
@@ -1354,7 +1354,7 @@ describe('app module', () => {
 
   describe('getApplicationNameForProtocol()', () => {
     // TODO: Linux CI doesn't have registered http & https handlers
-    ifit(!(process.env.CI && process.platform === 'linux'))('returns application names for common protocols', function () {
+    ifit(!(process.env.CI && (process.platform === 'linux' || process.platform === 'freebsd')))('returns application names for common protocols', function () {
       // We can't expect particular app names here, but these protocols should
       // at least have _something_ registered. Except on our Linux CI
       // environment apparently.
@@ -1372,7 +1372,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('getApplicationInfoForProtocol()', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('getApplicationInfoForProtocol()', () => {
     it('returns promise rejection for a bogus protocol', async function () {
       await expect(
         app.getApplicationInfoForProtocol('bogus-protocol://')
@@ -1422,7 +1422,7 @@ describe('app module', () => {
   });
 
   // FIXME Get these specs running on Linux CI
-  ifdescribe(process.platform !== 'linux')('getFileIcon() API', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('getFileIcon() API', () => {
     const iconPath = path.join(__dirname, 'fixtures/assets/icon.ico');
     const sizes = {
       small: 16,
@@ -1504,7 +1504,7 @@ describe('app module', () => {
           expect(entry.memory).to.have.property('privateBytes').that.is.greaterThan(0);
         }
 
-        if (process.platform !== 'linux') {
+        if (process.platform !== 'linux' && process.platform !== 'freebsd') {
           expect(entry.sandboxed).to.be.a('boolean');
         }
 
@@ -1578,7 +1578,7 @@ describe('app module', () => {
 
     it('succeeds with complete GPUInfo', async () => {
       const completeInfo = await getGPUInfo('complete');
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // For linux and macOS complete info is same as basic info
         await verifyBasicGPUInfo(completeInfo);
         const basicInfo = await getGPUInfo('basic');
@@ -1602,7 +1602,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(!(process.platform === 'linux' && (process.arch === 'arm64' || process.arch === 'arm')))('sandbox options', () => {
+  ifdescribe(!((process.platform === 'linux' || process.platform === 'freebsd') && (process.arch === 'arm64' || process.arch === 'arm')))('sandbox options', () => {
     let appProcess: cp.ChildProcess = null as any;
     let server: net.Server = null as any;
     const socketPath = process.platform === 'win32' ? '\\\\.\\pipe\\electron-mixed-sandbox' : '/tmp/electron-mixed-sandbox';
