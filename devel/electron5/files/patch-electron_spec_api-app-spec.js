--- electron/spec/api-app-spec.js.orig	2019-12-17 03:11:25 UTC
+++ electron/spec/api-app-spec.js
@@ -129,7 +129,7 @@ describe('app module', () => {
   describe('app.getLocaleCountryCode()', () => {
     it('should be empty or have length of two', () => {
       let expectedLength = 2
-      if (isCI && process.platform === 'linux') {
+      if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
         // Linux CI machines have no locale.
         expectedLength = 0
       }
@@ -189,7 +189,7 @@ describe('app module', () => {
     })
 
     it('exits gracefully', async function () {
-      if (!['darwin', 'linux'].includes(process.platform)) {
+      if (!['darwin', 'linux', 'freebsd'].includes(process.platform)) {
         this.skip()
         return
       }
@@ -289,7 +289,7 @@ describe('app module', () => {
     let w = null
 
     before(function () {
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd') {
         this.skip()
       }
     })
@@ -482,7 +482,7 @@ describe('app module', () => {
   describe('app.setBadgeCount', () => {
     const platformIsNotSupported =
         (process.platform === 'win32') ||
-        (process.platform === 'linux' && !app.isUnityRunning())
+        (process.platform === 'linux' && !app.isUnityRunning()) || (process.platform === 'freebsd')
     const platformIsSupported = !platformIsNotSupported
 
     const expectedBadgeCount = 42
@@ -536,7 +536,7 @@ describe('app module', () => {
     ]
 
     before(function () {
-      if (process.platform === 'linux' || process.mas) this.skip()
+      if (process.platform === 'linux' || process.platform === 'freebsd' || process.mas) this.skip()
     })
 
     beforeEach(() => {
@@ -665,7 +665,7 @@ describe('app module', () => {
     let w = null
 
     before(function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip()
       }
     })
@@ -859,7 +859,7 @@ describe('app module', () => {
     // doesn't affect nested `describe`s.
     beforeEach(function () {
       // FIXME Get these specs running on Linux CI
-      if (process.platform === 'linux' && isCI) {
+      if ((process.platform === 'linux' || process.platform === 'freebsd') && isCI) {
         this.skip()
       }
     })
@@ -1011,7 +1011,7 @@ describe('app module', () => {
 
     it('succeeds with complete GPUInfo', async () => {
       const completeInfo = await getGPUInfo('complete')
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // For linux and macOS complete info is same as basic info
         await verifyBasicGPUInfo(completeInfo)
         const basicInfo = await getGPUInfo('basic')
@@ -1039,7 +1039,7 @@ describe('app module', () => {
     const socketPath = process.platform === 'win32' ? '\\\\.\\pipe\\electron-mixed-sandbox' : '/tmp/electron-mixed-sandbox'
 
     beforeEach(function (done) {
-      if (process.platform === 'linux' && (process.arch === 'arm64' || process.arch === 'arm')) {
+      if ((process.platform === 'linux' || process.platform === 'freebsd') && (process.arch === 'arm64' || process.arch === 'arm')) {
         // Our ARM tests are run on VSTS rather than CircleCI, and the Docker
         // setup on VSTS disallows syscalls that Chrome requires for setting up
         // sandboxing.
