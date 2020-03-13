--- electron/spec-main/api-net-log-spec.js.orig	2020-02-10 19:08:32 UTC
+++ electron/spec-main/api-net-log-spec.js
@@ -124,7 +124,7 @@ describe('netLog module', () => {
   })
 
   it('should begin and end logging automatically when --log-net-log is passed', done => {
-    if (isCI && process.platform === 'linux') {
+    if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
       done()
       return
     }
@@ -144,7 +144,7 @@ describe('netLog module', () => {
   })
 
   it('should begin and end logging automtically when --log-net-log is passed, and behave correctly when .startLogging() and .stopLogging() is called', done => {
-    if (isCI && process.platform === 'linux') {
+    if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
       done()
       return
     }
@@ -167,7 +167,7 @@ describe('netLog module', () => {
   })
 
   it('should end logging automatically when only .startLogging() is called', done => {
-    if (isCI && process.platform === 'linux') {
+    if (isCI && (process.platform === 'linux' || process.platform === 'freebsd')) {
       done()
       return
     }
