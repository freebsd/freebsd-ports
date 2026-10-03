--- electron/spec/api-app.spec.ts.orig	2026-09-29 23:27:57 UTC
+++ electron/spec/api-app.spec.ts
@@ -126,7 +126,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('app.setDesktopName(name)', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('app.setDesktopName(name)', () => {
     it('sets the desktop name to the CHROME_DESKTOP environment variable', () => {
       const original = process.env.CHROME_DESKTOP;
       defer(() => {
@@ -155,11 +155,11 @@ describe('app module', () => {
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
@@ -201,7 +201,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux' && fs.existsSync('/usr/bin/dbus-daemon'))(
+  ifdescribe((process.platform === 'linux' || process.platform === 'freebsd') && fs.existsSync('/usr/bin/dbus-daemon'))(
     'when a D-Bus bus goes away',
     () => {
       it('exits cleanly instead of crashing', async () => {
@@ -292,7 +292,7 @@ describe('app module', () => {
       }
     });
 
-    ifit(['darwin', 'linux'].includes(process.platform))('exits gracefully', async function () {
+    ifit(['darwin', 'linux', 'freebsd'].includes(process.platform))('exits gracefully', async function () {
       const electronPath = process.execPath;
       const appPath = path.join(fixturesPath, 'api', 'singleton');
       appProcess = cp.spawn(electronPath, [appPath]);
@@ -490,7 +490,7 @@ describe('app module', () => {
   });
 
   // GitHub Actions macOS-13 runners used for x64 seem to have a problem with this test.
-  ifdescribe(process.platform !== 'linux' && !isMacOSx64)('app.{add|get|clear}RecentDocument(s)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && !isMacOSx64)('app.{add|get|clear}RecentDocument(s)', () => {
     const tempFiles = [
       path.join(fixturesPath, 'foo.txt'),
       path.join(fixturesPath, 'bar.txt'),
@@ -626,7 +626,7 @@ describe('app module', () => {
   //   let w = null
 
   //   before(function () {
-  //     if (process.platform !== 'linux') {
+  //     if (process.platform !== 'linux' && process.platform !== 'freebsd') {
   //       this.skip()
   //     }
   //   })
@@ -738,7 +738,7 @@ describe('app module', () => {
   });
 
   describe('app.badgeCount', () => {
-    const platformIsSupported = process.platform === 'darwin' || process.platform === 'linux';
+    const platformIsSupported = process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd';
 
     const expectedBadgeCount = 42;
 
@@ -771,7 +771,7 @@ describe('app module', () => {
   });
 
   ifdescribe(
-    process.platform !== 'linux' && !process.mas && (process.platform !== 'darwin' || process.arch === 'arm64')
+    process.platform !== 'linux' && process.platform !== 'freebsd' && !process.mas && (process.platform !== 'darwin' || process.arch === 'arm64')
   )('app.get/setLoginItemSettings API', function () {
     const isMac = process.platform === 'darwin';
     const isWin = process.platform === 'win32';
@@ -1115,7 +1115,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('accessibility support functionality', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('accessibility support functionality', () => {
     // These tests toggle a process-wide AXMode. Turn it back off so the rest of
     // the suite doesn't run with renderer accessibility enabled.
     afterEach(() => {
@@ -1391,7 +1391,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('select-client-certificate event', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('select-client-certificate event', () => {
     let w: BrowserWindow;
 
     before(function () {
@@ -1534,7 +1534,7 @@ describe('app module', () => {
 
   describe('getApplicationNameForProtocol()', () => {
     // TODO: Linux CI doesn't have registered http & https handlers
-    ifit(!(process.env.CI && process.platform === 'linux') && !isWayland)(
+    ifit(!(process.env.CI && (process.platform === 'linux' || process.platform === 'freebsd')) && !isWayland)(
       'returns application names for common protocols',
       function () {
         // We can't expect particular app names here, but these protocols should
@@ -1551,7 +1551,7 @@ describe('app module', () => {
       expect(app.getApplicationNameForProtocol('bogus-protocol://')).to.equal('');
     });
 
-    ifdescribe(process.platform === 'linux')('on Linux with mocked XDG dirs', () => {
+    ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('on Linux with mocked XDG dirs', () => {
       const desktopFileId = 'mock-browser.desktop';
       const mockDisplayName = 'Mock Browser';
       const mockScheme = 'mockproto';
@@ -1601,7 +1601,7 @@ describe('app module', () => {
     let xdgBinDir: string;
 
     before(() => {
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd') {
         return;
       }
 
@@ -1618,7 +1618,7 @@ describe('app module', () => {
     });
 
     after(() => {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         fs.rmSync(xdgDir, { recursive: true, force: true });
       }
     });
@@ -1630,7 +1630,7 @@ describe('app module', () => {
     });
 
     it('returns resolved promise with appPath, displayName and icon', async function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         const appInfo = await spawnProtocolInfoWithXdgMock(`${mockScheme}://`, xdgDataHome, xdgConfigHome);
         expect(appInfo.name).to.equal(mockDisplayName);
         expect(appInfo.path).to.equal('/usr/bin/true');
@@ -1644,7 +1644,7 @@ describe('app module', () => {
       expect(appInfo.icon).not.to.be.undefined();
     });
 
-    ifit(process.platform === 'linux')('resolves an executable name via PATH', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('resolves an executable name via PATH', async () => {
       const pathLookupExecutable = 'mock-browser';
       const pathLookupExecutablePath = path.join(xdgBinDir, pathLookupExecutable);
       const pathLookupDisplayName = 'Mock Browser PATH';
@@ -1678,7 +1678,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('default protocol client APIs', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('default protocol client APIs', () => {
     const protocol = 'electron-test-linux';
     const desktopFileId = 'electron-test.desktop';
     const protocolMimeType = `x-scheme-handler/${protocol}`;
@@ -1795,7 +1795,7 @@ describe('app module', () => {
   });
 
   // FIXME Get these specs running on Linux CI
-  ifdescribe(process.platform !== 'linux')('getFileIcon() API', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('getFileIcon() API', () => {
     const iconPath = path.join(import.meta.dirname, 'fixtures/assets/icon.ico');
     const sizes = {
       small: 16,
@@ -1877,7 +1877,7 @@ describe('app module', () => {
           expect(entry.memory).to.have.property('privateBytes').that.is.greaterThan(0);
         }
 
-        if (process.platform !== 'linux') {
+        if (process.platform !== 'linux' && process.platform !== 'freebsd') {
           expect(entry.sandboxed).to.be.a('boolean');
         }
 
@@ -1894,7 +1894,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('GDK_BACKEND', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('GDK_BACKEND', () => {
     const fixture = path.join(fixturesPath, 'apps', 'gdk-backend');
     const run = async (env: NodeJS.ProcessEnv) => {
       const child = cp.spawn(process.execPath, [fixture], { env, stdio: ['ignore', 'pipe', 'ignore'] });
@@ -1991,7 +1991,7 @@ describe('app module', () => {
         if (isGpuUnavailable(error as Error)) return this.skip();
         throw error;
       }
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // For linux and macOS complete info is same as basic info
         await verifyBasicGPUInfo(completeInfo);
         const basicInfo = await getGPUInfo('basic');
@@ -2015,7 +2015,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(!(process.platform === 'linux' && process.arch === 'arm64'))('sandbox options', () => {
+  ifdescribe(!((process.platform === 'linux' || process.platform === 'freebsd') && process.arch === 'arm64'))('sandbox options', () => {
     let appProcess: cp.ChildProcess = null as any;
     let server: net.Server = null as any;
     const socketPath =
