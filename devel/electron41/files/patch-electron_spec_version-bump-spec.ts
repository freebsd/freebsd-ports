--- electron/spec/version-bump-spec.ts.orig	2026-05-07 20:19:20 UTC
+++ electron/spec/version-bump-spec.ts
@@ -54,7 +54,7 @@ describe('version-bumper', () => {
 }
 
 describe('version-bumper', () => {
-  ifdescribe(!(process.platform === 'linux' && process.arch.indexOf('arm') === 0) && process.platform !== 'darwin')(
+  ifdescribe(!((process.platform === 'linux' || process.platform === 'freebsd') && process.arch.indexOf('arm') === 0) && process.platform !== 'darwin')(
     'nextVersion',
     () => {
       describe('bump versions', () => {
