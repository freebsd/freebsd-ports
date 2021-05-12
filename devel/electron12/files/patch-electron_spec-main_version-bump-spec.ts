--- electron/spec-main/version-bump-spec.ts.orig	2021-01-22 23:55:24 UTC
+++ electron/spec-main/version-bump-spec.ts
@@ -43,7 +43,7 @@ describe('version-bumper', () => {
 
   // On macOS Circle CI we don't have a real git environment due to running
   // gclient sync on a linux machine. These tests therefore don't run as expected.
-  ifdescribe(!(process.platform === 'linux' && process.arch === 'arm') && process.platform !== 'darwin')('nextVersion', () => {
+  ifdescribe(!((process.platform === 'linux' || process.platform === 'freebsd') && process.arch === 'arm') && process.platform !== 'darwin')('nextVersion', () => {
     const nightlyPattern = /[0-9.]*(-nightly.(\d{4})(\d{2})(\d{2}))$/g;
     const betaPattern = /[0-9.]*(-beta[0-9.]*)/g;
 
