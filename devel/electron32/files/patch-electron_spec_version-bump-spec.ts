--- electron/spec/version-bump-spec.ts.orig	2024-07-24 17:23:33 UTC
+++ electron/spec/version-bump-spec.ts
@@ -90,7 +90,7 @@ describe('version-bumper', () => {
     });
   });
 
-  ifdescribe(!(process.platform === 'linux' && process.arch.indexOf('arm') === 0) && process.platform !== 'darwin')('nextVersion', () => {
+  ifdescribe(!((process.platform === 'linux' || process.platform === 'freebsd') && process.arch.indexOf('arm') === 0) && process.platform !== 'darwin')('nextVersion', () => {
     describe('bump versions', () => {
       const nightlyPattern = /[0-9.]*(-nightly.(\d{4})(\d{2})(\d{2}))$/g;
       const betaPattern = /[0-9.]*(-beta[0-9.]*)/g;
