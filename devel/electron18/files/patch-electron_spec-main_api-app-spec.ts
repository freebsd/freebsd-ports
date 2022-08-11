--- electron/spec-main/api-app-spec.ts.orig	2022-05-25 15:32:14 UTC
+++ electron/spec-main/api-app-spec.ts
@@ -174,7 +174,7 @@ describe('app module', () => {
     });
 
     it('exits gracefully', async function () {
-      if (!['darwin', 'linux'].includes(process.platform)) {
+      if (!['darwin', 'linux', 'freebsd'].includes(process.platform)) {
         this.skip();
         return;
       }
@@ -436,7 +436,7 @@ describe('app module', () => {
   //   let w = null
 
   //   before(function () {
-  //     if (process.platform !== 'linux') {
+  //     if (process.platform !== 'linux' && process.platform !== 'freebsd') {
   //       this.skip()
   //     }
   //   })
@@ -559,7 +559,7 @@ describe('app module', () => {
   describe('app.badgeCount', () => {
     const platformIsNotSupported =
         (process.platform === 'win32') ||
-        (process.platform === 'linux' && !app.isUnityRunning());
+	((process.platform === 'linux' || process.platform === 'freebsd') && !app.isUnityRunning());
 
     const expectedBadgeCount = 42;
 
@@ -603,7 +603,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux' && !process.mas)('app.get/setLoginItemSettings API', function () {
+  ifdescribe((process.platform !== 'linux' && process.platform !== 'freebsd') && !process.mas)('app.get/setLoginItemSettings API', function () {
     const updateExe = path.resolve(path.dirname(process.execPath), '..', 'Update.exe');
     const processStartArgs = [
       '--processStart', `"${path.basename(process.execPath)}"`,
@@ -920,7 +920,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('accessibilitySupportEnabled property', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('accessibilitySupportEnabled property', () => {
     it('with properties', () => {
       it('can set accessibility support enabled', () => {
         expect(app.accessibilitySupportEnabled).to.eql(false);
@@ -1038,7 +1038,7 @@ describe('app module', () => {
     let w: BrowserWindow;
 
     before(function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip();
       }
       session.fromPartition('empty-certificate').setCertificateVerifyProc((req, cb) => { cb(0); });
@@ -1179,7 +1179,7 @@ describe('app module', () => {
       // We can't expect particular app names here, but these protocols should
       // at least have _something_ registered. Except on our Linux CI
       // environment apparently.
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip();
       }
 
@@ -1197,7 +1197,7 @@ describe('app module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('getApplicationInfoForProtocol()', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('getApplicationInfoForProtocol()', () => {
     it('returns promise rejection for a bogus protocol', async function () {
       await expect(
         app.getApplicationInfoForProtocol('bogus-protocol://')
@@ -1247,7 +1247,7 @@ describe('app module', () => {
   });
 
   // FIXME Get these specs running on Linux CI
-  ifdescribe(process.platform !== 'linux')('getFileIcon() API', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('getFileIcon() API', () => {
     const iconPath = path.join(__dirname, 'fixtures/assets/icon.ico');
     const sizes = {
       small: 16,
@@ -1328,7 +1328,7 @@ describe('app module', () => {
           expect(entry.memory).to.have.property('privateBytes').that.is.greaterThan(0);
         }
 
-        if (process.platform !== 'linux') {
+        if (process.platform !== 'linux' && process.platform !== 'freebsd') {
           expect(entry.sandboxed).to.be.a('boolean');
         }
 
@@ -1354,7 +1354,7 @@ describe('app module', () => {
   });
 
   // FIXME https://github.com/electron/electron/issues/24224
-  ifdescribe(process.platform !== 'linux')('getGPUInfo() API', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('getGPUInfo() API', () => {
     const appPath = path.join(fixturesPath, 'api', 'gpu-info.js');
 
     const getGPUInfo = async (type: string) => {
@@ -1403,7 +1403,7 @@ describe('app module', () => {
 
     it('succeeds with complete GPUInfo', async () => {
       const completeInfo = await getGPUInfo('complete');
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // For linux and macOS complete info is same as basic info
         await verifyBasicGPUInfo(completeInfo);
         const basicInfo = await getGPUInfo('basic');
@@ -1433,7 +1433,7 @@ describe('app module', () => {
     const socketPath = process.platform === 'win32' ? '\\\\.\\pipe\\electron-mixed-sandbox' : '/tmp/electron-mixed-sandbox';
 
     beforeEach(function (done) {
-      if (process.platform === 'linux' && (process.arch === 'arm64' || process.arch === 'arm')) {
+      if ((process.platform === 'linux' || process.platform === 'freebsd') && (process.arch === 'arm64' || process.arch === 'arm')) {
         // Our ARM tests are run on VSTS rather than CircleCI, and the Docker
         // setup on VSTS disallows syscalls that Chrome requires for setting up
         // sandboxing.
