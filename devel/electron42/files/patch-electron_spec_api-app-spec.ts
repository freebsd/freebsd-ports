--- electron/spec/api-app-spec.ts.orig	2026-05-26 16:24:13 UTC
+++ electron/spec/api-app-spec.ts
@@ -136,11 +136,11 @@ describe('app module', () => {
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
@@ -219,7 +219,7 @@ describe('app module', () => {
       expect(code).to.equal(123, 'exit code should be 123, if you see this please tag @MarshallOfSound');
     });
 
-    ifit(['darwin', 'linux'].includes(process.platform))('exits gracefully', async function () {
+    ifit(['darwin', 'linux', 'freebsd'].includes(process.platform))('exits gracefully', async function () {
       const electronPath = process.execPath;
       const appPath = path.join(fixturesPath, 'api', 'singleton');
       appProcess = cp.spawn(electronPath, [appPath]);
@@ -390,7 +390,7 @@ describe('app module', () => {
   });
 
   // GitHub Actions macOS-13 runners used for x64 seem to have a problem with this test.
-  ifdescribe(process.platform !== 'linux' && !isMacOSx64)('app.{add|get|clear}RecentDocument(s)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && !isMacOSx64)('app.{add|get|clear}RecentDocument(s)', () => {
     const tempFiles = [
       path.join(fixturesPath, 'foo.txt'),
       path.join(fixturesPath, 'bar.txt'),
@@ -519,7 +519,7 @@ describe('app module', () => {
   //   let w = null
 
   //   before(function () {
-  //     if (process.platform !== 'linux') {
+  //     if (process.platform !== 'linux' && process.platform !== 'freebsd') {
   //       this.skip()
   //     }
   //   })
@@ -632,7 +632,7 @@ describe('app module', () => {
 
   describe('app.badgeCount', () => {
     const platformIsNotSupported =
-      process.platform === 'win32' || (process.platform === 'linux' && !app.isUnityRunning());
+      process.platform === 'win32' || (process.platform === 'linux' && !app.isUnityRunning()) || process.platform === 'freebsd';
 
     const expectedBadgeCount = 42;
 
@@ -679,7 +679,7 @@ describe('app module', () => {
   });
 
   ifdescribe(
-    process.platform !== 'linux' && !process.mas && (process.platform !== 'darwin' || process.arch === 'arm64')
+    process.platform !== 'linux' && process.platform !== 'freebsd' && !process.mas && (process.platform !== 'darwin' || process.arch === 'arm64')
   )('app.get/setLoginItemSettings API', function () {
     const isMac = process.platform === 'darwin';
     const isWin = process.platform === 'win32';
@@ -1096,7 +1096,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('accessibility support functionality', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('accessibility support functionality', () => {
     it('is mutable', () => {
       const values = [false, true, false];
       const setters: Array<(arg: boolean) => void> = [
@@ -1366,7 +1366,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('select-client-certificate event', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('select-client-certificate event', () => {
     let w: BrowserWindow;
 
     before(function () {
@@ -1509,7 +1509,7 @@ describe('app module', () => {
 
   describe('getApplicationNameForProtocol()', () => {
     // TODO: Linux CI doesn't have registered http & https handlers
-    ifit(!(process.env.CI && process.platform === 'linux') && !isWayland)(
+    ifit(!(process.env.CI && (process.platform === 'linux' || process.platform === 'freebsd')) && !isWayland)(
       'returns application names for common protocols',
       function () {
         // We can't expect particular app names here, but these protocols should
@@ -1526,7 +1526,7 @@ describe('app module', () => {
       expect(app.getApplicationNameForProtocol('bogus-protocol://')).to.equal('');
     });
 
-    ifdescribe(process.platform === 'linux')('on Linux with mocked XDG dirs', () => {
+    ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('on Linux with mocked XDG dirs', () => {
       const desktopFileId = 'mock-browser.desktop';
       const mockDisplayName = 'Mock Browser';
       const mockScheme = 'mockproto';
@@ -1576,7 +1576,7 @@ describe('app module', () => {
     let xdgBinDir: string;
 
     before(() => {
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd') {
         return;
       }
 
@@ -1593,7 +1593,7 @@ describe('app module', () => {
     });
 
     after(() => {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         fs.rmSync(xdgDir, { recursive: true, force: true });
       }
     });
@@ -1605,7 +1605,7 @@ describe('app module', () => {
     });
 
     it('returns resolved promise with appPath, displayName and icon', async function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         const appInfo = await spawnProtocolInfoWithXdgMock(`${mockScheme}://`, xdgDataHome, xdgConfigHome);
         expect(appInfo.name).to.equal(mockDisplayName);
         expect(appInfo.path).to.equal('/usr/bin/true');
@@ -1619,7 +1619,7 @@ describe('app module', () => {
       expect(appInfo.icon).not.to.be.undefined();
     });
 
-    ifit(process.platform === 'linux')('resolves an executable name via PATH', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('resolves an executable name via PATH', async () => {
       const pathLookupExecutable = 'mock-browser';
       const pathLookupExecutablePath = path.join(xdgBinDir, pathLookupExecutable);
       const pathLookupDisplayName = 'Mock Browser PATH';
@@ -1653,7 +1653,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('default protocol client APIs with mocked XDG settings', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('default protocol client APIs with mocked XDG settings', () => {
     const protocol = 'electron-test-linux';
     const desktopFileId = 'electron-test.desktop';
     const protocolMimeType = `x-scheme-handler/${protocol}`;
@@ -1792,7 +1792,7 @@ describe('app module', () => {
   });
 
   // FIXME Get these specs running on Linux CI
-  ifdescribe(process.platform !== 'linux')('getFileIcon() API', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('getFileIcon() API', () => {
     const iconPath = path.join(__dirname, 'fixtures/assets/icon.ico');
     const sizes = {
       small: 16,
@@ -1874,7 +1874,7 @@ describe('app module', () => {
           expect(entry.memory).to.have.property('privateBytes').that.is.greaterThan(0);
         }
 
-        if (process.platform !== 'linux') {
+        if (process.platform !== 'linux' && process.platform !== 'freebsd') {
           expect(entry.sandboxed).to.be.a('boolean');
         }
 
@@ -1943,7 +1943,7 @@ describe('app module', () => {
 
     it('succeeds with complete GPUInfo', async () => {
       const completeInfo = await getGPUInfo('complete');
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // For linux and macOS complete info is same as basic info
         await verifyBasicGPUInfo(completeInfo);
         const basicInfo = await getGPUInfo('basic');
@@ -1967,7 +1967,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(!(process.platform === 'linux' && (process.arch === 'arm64' || process.arch === 'arm')))(
+  ifdescribe(!((process.platform === 'linux' || process.platform === 'freebsd') && (process.arch === 'arm64' || process.arch === 'arm')))(
     'sandbox options',
     () => {
       let appProcess: cp.ChildProcess = null as any;
