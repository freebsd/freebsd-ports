--- electron/spec/api-net-log-spec.js.orig	2019-09-11 17:30:11 UTC
+++ electron/spec/api-net-log-spec.js
@@ -127,7 +127,7 @@ describe('netLog module', () => {
   })
 
   it('should begin and end logging automatically when --log-net-log is passed', done => {
-    if (isCI && process.platform === 'linux') {
+    if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
       done()
       return
     }
@@ -148,7 +148,7 @@ describe('netLog module', () => {
 
   // FIXME(deepak1556): Ch69 follow up.
   it('should begin and end logging automtically when --log-net-log is passed, and behave correctly when .startLogging() and .stopLogging() is called', done => {
-    if (isCI && process.platform === 'linux') {
+    if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
       done()
       return
     }
@@ -171,7 +171,7 @@ describe('netLog module', () => {
   })
 
   it('should end logging automatically when only .startLogging() is called', done => {
-    if (isCI && process.platform === 'linux') {
+    if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
       done()
       return
     }
