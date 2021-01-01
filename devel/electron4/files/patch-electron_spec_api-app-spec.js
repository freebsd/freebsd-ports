--- electron/spec/api-app-spec.js.orig	2019-07-01 21:24:47 UTC
+++ electron/spec/api-app-spec.js
@@ -175,7 +175,7 @@ describe('app module', () => {
     })
 
     it('exits gracefully', async function () {
-      if (!['darwin', 'linux'].includes(process.platform)) {
+        if (!['darwin', 'linux', 'freebsd'].includes(process.platform)) {
         this.skip()
         return
       }
@@ -275,7 +275,7 @@ describe('app module', () => {
     let w = null
 
     before(function () {
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd') {
         this.skip()
       }
     })
@@ -422,7 +422,8 @@ describe('app module', () => {
   describe('app.setBadgeCount', () => {
     const platformIsNotSupported =
         (process.platform === 'win32') ||
-        (process.platform === 'linux' && !app.isUnityRunning())
+        (process.platform === 'linux' && !app.isUnityRunning()) ||
+        (process.platform === 'freebsd')
     const platformIsSupported = !platformIsNotSupported
 
     const expectedBadgeCount = 42
@@ -476,7 +477,7 @@ describe('app module', () => {
     ]
 
     before(function () {
-      if (process.platform === 'linux' || process.mas) this.skip()
+      if (process.platform === 'linux' || process.platform === 'freebsd' || process.mas) this.skip()
     })
 
     beforeEach(() => {
@@ -605,7 +606,7 @@ describe('app module', () => {
     let w = null
 
     before(function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip()
       }
     })
@@ -798,7 +799,7 @@ describe('app module', () => {
     // doesn't affect nested `describe`s.
     beforeEach(function () {
       // FIXME Get these specs running on Linux CI
-      if (process.platform === 'linux' && isCI) {
+      if ((process.platform === 'linux' || process.platform === 'freebsd') && isCI) {
         this.skip()
       }
     })
@@ -936,7 +937,7 @@ describe('app module', () => {
 
     it('succeeds with complete GPUInfo', async () => {
       const completeInfo = await getGPUInfo('complete')
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // For linux and macOS complete info is same as basic info
         await verifyBasicGPUInfo(completeInfo)
         const basicInfo = await getGPUInfo('basic')
@@ -967,7 +968,7 @@ describe('app module', () => {
       // XXX(alexeykuzmin): Calling `.skip()` inside a `before` hook
       // doesn't affect nested `describe`s.
       // FIXME Get these specs running on Linux
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip()
       }
 
