--- electron/spec/api-app-spec.js.orig	2019-05-02 21:34:52 UTC
+++ electron/spec/api-app-spec.js
@@ -174,7 +174,7 @@ describe('app module', () => {
     })
 
     it('exits gracefully', async function () {
-      if (!['darwin', 'linux'].includes(process.platform)) {
+        if (!['darwin', 'linux', 'freebsd'].includes(process.platform)) {
         this.skip()
         return
       }
@@ -274,7 +274,7 @@ describe('app module', () => {
     let w = null
 
     before(function () {
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd') {
         this.skip()
       }
     })
@@ -421,7 +421,8 @@ describe('app module', () => {
   describe('app.setBadgeCount', () => {
     const platformIsNotSupported =
         (process.platform === 'win32') ||
-        (process.platform === 'linux' && !app.isUnityRunning())
+        (process.platform === 'linux' && !app.isUnityRunning()) ||
+        (process.platform === 'freebsd')
     const platformIsSupported = !platformIsNotSupported
 
     const expectedBadgeCount = 42
@@ -475,7 +476,7 @@ describe('app module', () => {
     ]
 
     before(function () {
-      if (process.platform === 'linux' || process.mas) this.skip()
+      if (process.platform === 'linux' || process.platform === 'freebsd' || process.mas) this.skip()
     })
 
     beforeEach(() => {
@@ -582,7 +583,7 @@ describe('app module', () => {
     let w = null
 
     before(function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip()
       }
     })
@@ -775,7 +776,7 @@ describe('app module', () => {
     // doesn't affect nested `describe`s.
     beforeEach(function () {
       // FIXME Get these specs running on Linux CI
-      if (process.platform === 'linux' && isCI) {
+      if ((process.platform === 'linux' || process.platform === 'freebsd') && isCI) {
         this.skip()
       }
     })
@@ -913,7 +914,7 @@ describe('app module', () => {
 
     it('succeeds with complete GPUInfo', async () => {
       const completeInfo = await getGPUInfo('complete')
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // For linux and macOS complete info is same as basic info
         await verifyBasicGPUInfo(completeInfo)
         const basicInfo = await getGPUInfo('basic')
@@ -944,7 +945,7 @@ describe('app module', () => {
       // XXX(alexeykuzmin): Calling `.skip()` inside a `before` hook
       // doesn't affect nested `describe`s.
       // FIXME Get these specs running on Linux
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip()
       }
 
