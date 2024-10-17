--- electron/spec/version-bump-spec.ts.orig	2024-10-09 13:53:06 UTC
+++ electron/spec/version-bump-spec.ts
@@ -53,7 +53,7 @@ describe('version-bumper', () => {
 }
 
 describe('version-bumper', () => {
-  ifdescribe(!(process.platform === 'linux' && process.arch.indexOf('arm') === 0) && process.platform !== 'darwin')('nextVersion', () => {
+  ifdescribe(!((process.platform === 'linux' || process.platform === 'freebsd') && process.arch.indexOf('arm') === 0) && process.platform !== 'darwin')('nextVersion', () => {
     describe('bump versions', () => {
       const nightlyPattern = /[0-9.]*(-nightly.(\d{4})(\d{2})(\d{2}))$/g;
       const betaPattern = /[0-9.]*(-beta[0-9.]*)/g;
