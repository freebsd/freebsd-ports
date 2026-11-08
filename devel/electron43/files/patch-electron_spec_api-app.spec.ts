--- electron/spec/api-app.spec.ts.orig	2026-10-30 20:58:40 UTC
+++ electron/spec/api-app.spec.ts
@@ -131,7 +131,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('app.setDesktopName(name)', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('app.setDesktopName(name)', () => {
     it('sets the desktop name to the CHROME_DESKTOP environment variable', () => {
       const original = process.env.CHROME_DESKTOP;
       defer(() => {
@@ -160,11 +160,11 @@ describe('app module', () => {
   });
 
   describe('app.getPreferredSystemLanguages()', () => {
-    ifit(process.platform !== 'linux')('should not be empty', () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should not be empty', () => {
       expect(app.getPreferredSystemLanguages().length).not.toBe(0);
     });
 
-    ifit(process.platform === 'linux')('should be empty or contain C entry', () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('should be empty or contain C entry', () => {
       const languages = app.getPreferredSystemLanguages();
       if (languages.length) {
         expect(languages).not.toContain('C');
@@ -206,7 +206,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux' && fs.existsSync('/usr/bin/dbus-daemon'))(
+  ifdescribe((process.platform === 'linux' || process.platform === 'freebsd') && fs.existsSync('/usr/bin/dbus-daemon'))(
     'when a D-Bus bus goes away',
     () => {
       it('exits cleanly instead of crashing', async () => {
@@ -378,7 +378,7 @@ describe('app module', () => {
     // A missing display makes toolkit initialisation fail before the main loop
     // runs; that early return must still tear the JS environment down cleanly.
     // Skipped under ASan for the same reason as the test above.
-    ifit(process.platform === 'linux' && !process.env.IS_ASAN)(
+    ifit((process.platform === 'linux' || process.platform === 'freebsd') && !process.env.IS_ASAN)(
       'exits with code 1 when no display is available',
       async () => {
         const appPath = path.join(fixturesPath, 'api', 'no-display');
@@ -399,7 +399,7 @@ describe('app module', () => {
       }
     );
 
-    ifit(['darwin', 'linux'].includes(process.platform))('exits gracefully', async () => {
+    ifit(['darwin', 'linux', 'freebsd'].includes(process.platform))('exits gracefully', async () => {
       const electronPath = process.execPath;
       const appPath = path.join(fixturesPath, 'api', 'singleton');
       appProcess = cp.spawn(electronPath, [appPath]);
@@ -632,7 +632,7 @@ describe('app module', () => {
   });
 
   // GitHub Actions macOS-13 runners used for x64 seem to have a problem with this test.
-  ifdescribe(process.platform !== 'linux' && !isMacOSx64)('app.{add|get|clear}RecentDocument(s)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && !isMacOSx64)('app.{add|get|clear}RecentDocument(s)', () => {
     const tempFiles = [
       path.join(fixturesPath, 'foo.txt'),
       path.join(fixturesPath, 'bar.txt'),
@@ -769,7 +769,7 @@ describe('app module', () => {
   //   let w = null
 
   //   before(function () {
-  //     if (process.platform !== 'linux') {
+  //     if (process.platform !== 'linux' && process.platform !== 'freebsd') {
   //       this.skip()
   //     }
   //   })
@@ -882,7 +882,7 @@ describe('app module', () => {
 
   describe('app.badgeCount', () => {
     const platformIsNotSupported =
-      process.platform === 'win32' || (process.platform === 'linux' && !app.isUnityRunning());
+      process.platform === 'win32' || (process.platform === 'linux' && !app.isUnityRunning()) || process.platform === 'freebsd';
 
     const expectedBadgeCount = 42;
 
@@ -929,7 +929,7 @@ describe('app module', () => {
   });
 
   ifdescribe(
-    process.platform !== 'linux' && !process.mas && (process.platform !== 'darwin' || process.arch === 'arm64')
+    process.platform !== 'linux' && process.platform !== 'freebsd' && !process.mas && (process.platform !== 'darwin' || process.arch === 'arm64')
   )('app.get/setLoginItemSettings API', () => {
     const isMac = process.platform === 'darwin';
     const isWin = process.platform === 'win32';
@@ -1356,7 +1356,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('accessibility support functionality', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('accessibility support functionality', () => {
     // These tests toggle a process-wide AXMode. Turn it back off so the rest of
     // the suite doesn't run with renderer accessibility enabled.
     afterEach(() => {
@@ -1639,7 +1639,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('select-client-certificate event', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('select-client-certificate event', () => {
     let w: BrowserWindow;
 
     beforeAll(() => {
@@ -1785,7 +1785,7 @@ describe('app module', () => {
 
   describe('getApplicationNameForProtocol()', () => {
     // TODO: Linux CI doesn't have registered http & https handlers
-    ifit(!(process.env.CI && process.platform === 'linux') && !isWayland)(
+    ifit(!(process.env.CI && (process.platform === 'linux' || process.platform === 'freebsd')) && !isWayland)(
       'returns application names for common protocols',
       () => {
         // We can't expect particular app names here, but these protocols should
@@ -1802,7 +1802,7 @@ describe('app module', () => {
       expect(app.getApplicationNameForProtocol('bogus-protocol://')).toBe('');
     });
 
-    ifdescribe(process.platform === 'linux')('on Linux with mocked XDG dirs', () => {
+    ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('on Linux with mocked XDG dirs', () => {
       const desktopFileId = 'mock-browser.desktop';
       const mockDisplayName = 'Mock Browser';
       const mockScheme = 'mockproto';
@@ -1852,7 +1852,7 @@ describe('app module', () => {
     let xdgBinDir: string;
 
     beforeAll(() => {
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd') {
         return;
       }
 
@@ -1869,7 +1869,7 @@ describe('app module', () => {
     });
 
     afterAll(() => {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         fs.rmSync(xdgDir, { recursive: true, force: true });
       }
     });
@@ -1881,7 +1881,7 @@ describe('app module', () => {
     });
 
     it('returns resolved promise with appPath, displayName and icon', async () => {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         const appInfo = await spawnProtocolInfoWithXdgMock(`${mockScheme}://`, xdgDataHome, xdgConfigHome);
         expect(appInfo.name).toBe(mockDisplayName);
         expect(appInfo.path).toBe('/usr/bin/true');
@@ -1895,7 +1895,7 @@ describe('app module', () => {
       expect(appInfo.icon).not.toBeUndefined();
     });
 
-    ifit(process.platform === 'linux')('resolves an executable name via PATH', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('resolves an executable name via PATH', async () => {
       const pathLookupExecutable = 'mock-browser';
       const pathLookupExecutablePath = path.join(xdgBinDir, pathLookupExecutable);
       const pathLookupDisplayName = 'Mock Browser PATH';
@@ -1929,7 +1929,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('default protocol client APIs', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('default protocol client APIs', () => {
     const protocol = 'electron-test-linux';
     const desktopFileId = 'electron-test.desktop';
     const protocolMimeType = `x-scheme-handler/${protocol}`;
@@ -2046,7 +2046,7 @@ describe('app module', () => {
   });
 
   // FIXME Get these specs running on Linux CI
-  ifdescribe(process.platform !== 'linux')('getFileIcon() API', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('getFileIcon() API', () => {
     const iconPath = path.join(import.meta.dirname, 'fixtures/assets/icon.ico');
     const sizes = {
       small: 16,
@@ -2135,7 +2135,7 @@ describe('app module', () => {
           expect(entry.memory.privateBytes).toBeGreaterThan(0);
         }
 
-        if (process.platform !== 'linux') {
+        if (process.platform !== 'linux' && process.platform !== 'freebsd') {
           expect(entry.sandboxed).toBeTypeOf('boolean');
         }
 
@@ -2152,7 +2152,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('GDK_BACKEND', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('GDK_BACKEND', () => {
     const fixture = path.join(fixturesPath, 'apps', 'gdk-backend');
     // Wait for the app to exit, not just for its output. Otherwise the next
     // test (or retry) launches the fixture again while this copy is still
@@ -2235,7 +2235,7 @@ describe('app module', () => {
 
     it('succeeds with complete GPUInfo', async () => {
       const completeInfo = await getGPUInfo('complete');
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // For linux and macOS complete info is same as basic info
         await verifyBasicGPUInfo(completeInfo);
         const basicInfo = await getGPUInfo('basic');
@@ -2258,7 +2258,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(!(process.platform === 'linux' && (process.arch === 'arm64' || process.arch === 'arm')))(
+  ifdescribe(!((process.platform === 'linux' || process.platform === 'freebsd') && (process.arch === 'arm64' || process.arch === 'arm')))(
     'sandbox options',
     () => {
       let appProcess: cp.ChildProcess = null as any;
