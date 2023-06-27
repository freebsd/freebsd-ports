--- electron/spec/api-app-spec.ts.orig	2023-05-31 14:28:29 UTC
+++ electron/spec/api-app-spec.ts
@@ -121,11 +121,11 @@ describe('app module', () => {
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
@@ -188,7 +188,7 @@ describe('app module', () => {
       expect(code).to.equal(123, 'exit code should be 123, if you see this please tag @MarshallOfSound');
     });
 
-    ifit(['darwin', 'linux'].includes(process.platform))('exits gracefully', async function () {
+    ifit(['darwin', 'linux', 'freebsd'].includes(process.platform))('exits gracefully', async function () {
       const electronPath = process.execPath;
       const appPath = path.join(fixturesPath, 'api', 'singleton');
       appProcess = cp.spawn(electronPath, [appPath]);
@@ -442,7 +442,7 @@ describe('app module', () => {
   //   let w = null
 
   //   before(function () {
-  //     if (process.platform !== 'linux') {
+  //     if (process.platform !== 'linux' && process.platform !== 'freebsd') {
   //       this.skip()
   //     }
   //   })
@@ -565,7 +565,7 @@ describe('app module', () => {
   describe('app.badgeCount', () => {
     const platformIsNotSupported =
         (process.platform === 'win32') ||
-        (process.platform === 'linux' && !app.isUnityRunning());
+	((process.platform === 'linux' || process.platform === 'freebsd') && !app.isUnityRunning());
 
     const expectedBadgeCount = 42;
 
@@ -609,7 +609,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux' && !process.mas)('app.get/setLoginItemSettings API', function () {
+  ifdescribe((process.platform !== 'linux' && process.platform !== 'freebsd') && !process.mas)('app.get/setLoginItemSettings API', function () {
     const updateExe = path.resolve(path.dirname(process.execPath), '..', 'Update.exe');
     const processStartArgs = [
       '--processStart', `"${path.basename(process.execPath)}"`,
@@ -924,7 +924,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('accessibilitySupportEnabled property', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('accessibilitySupportEnabled property', () => {
     it('with properties', () => {
       it('can set accessibility support enabled', () => {
         expect(app.accessibilitySupportEnabled).to.eql(false);
@@ -1086,7 +1086,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('select-client-certificate event', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('select-client-certificate event', () => {
     let w: BrowserWindow;
 
     before(function () {
@@ -1221,7 +1221,7 @@ describe('app module', () => {
 
   describe('getApplicationNameForProtocol()', () => {
     // TODO: Linux CI doesn't have registered http & https handlers
-    ifit(!(process.env.CI && process.platform === 'linux'))('returns application names for common protocols', function () {
+    ifit(!(process.env.CI && (process.platform === 'linux' || process.platform === 'freebsd')))('returns application names for common protocols', function () {
       // We can't expect particular app names here, but these protocols should
       // at least have _something_ registered. Except on our Linux CI
       // environment apparently.
@@ -1239,7 +1239,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('getApplicationInfoForProtocol()', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('getApplicationInfoForProtocol()', () => {
     it('returns promise rejection for a bogus protocol', async function () {
       await expect(
         app.getApplicationInfoForProtocol('bogus-protocol://')
@@ -1289,7 +1289,7 @@ describe('app module', () => {
   });
 
   // FIXME Get these specs running on Linux CI
-  ifdescribe(process.platform !== 'linux')('getFileIcon() API', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('getFileIcon() API', () => {
     const iconPath = path.join(__dirname, 'fixtures/assets/icon.ico');
     const sizes = {
       small: 16,
@@ -1370,7 +1370,7 @@ describe('app module', () => {
           expect(entry.memory).to.have.property('privateBytes').that.is.greaterThan(0);
         }
 
-        if (process.platform !== 'linux') {
+        if (process.platform !== 'linux' && process.platform !== 'freebsd') {
           expect(entry.sandboxed).to.be.a('boolean');
         }
 
@@ -1396,7 +1396,7 @@ describe('app module', () => {
   });
 
   // FIXME https://github.com/electron/electron/issues/24224
-  ifdescribe(process.platform !== 'linux')('getGPUInfo() API', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('getGPUInfo() API', () => {
     const appPath = path.join(fixturesPath, 'api', 'gpu-info.js');
 
     const getGPUInfo = async (type: string) => {
@@ -1445,7 +1445,7 @@ describe('app module', () => {
 
     it('succeeds with complete GPUInfo', async () => {
       const completeInfo = await getGPUInfo('complete');
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // For linux and macOS complete info is same as basic info
         await verifyBasicGPUInfo(completeInfo);
         const basicInfo = await getGPUInfo('basic');
@@ -1469,7 +1469,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(!(process.platform === 'linux' && (process.arch === 'arm64' || process.arch === 'arm')))('sandbox options', () => {
+  ifdescribe(!((process.platform === 'linux' || process.platform === 'freebsd') && (process.arch === 'arm64' || process.arch === 'arm')))('sandbox options', () => {
     // Our ARM tests are run on VSTS rather than CircleCI, and the Docker
     // setup on VSTS disallows syscalls that Chrome requires for setting up
     // sandboxing.
