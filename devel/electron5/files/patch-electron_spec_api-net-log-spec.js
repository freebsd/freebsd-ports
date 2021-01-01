--- electron/spec/api-net-log-spec.js.orig	2019-05-16 02:08:40 UTC
+++ electron/spec/api-net-log-spec.js
@@ -95,7 +95,7 @@ describe('netLog module', () => {
   })
 
   it('should begin and end logging automatically when --log-net-log is passed', done => {
-    if (isCI && process.platform === 'linux') {
+    if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
       done()
       return
     }
@@ -116,7 +116,7 @@ describe('netLog module', () => {
 
   // FIXME(deepak1556): Ch69 follow up.
   it('should begin and end logging automtically when --log-net-log is passed, and behave correctly when .startLogging() and .stopLogging() is called', done => {
-    if (isCI && process.platform === 'linux') {
+    if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
       done()
       return
     }
@@ -139,7 +139,7 @@ describe('netLog module', () => {
   })
 
   it('should end logging automatically when only .startLogging() is called', done => {
-    if (isCI && process.platform === 'linux') {
+    if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
       done()
       return
     }
