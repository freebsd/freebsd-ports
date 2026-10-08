--- electron/spec/api-shell.spec.ts.orig	2026-10-07 13:38:33 UTC
+++ electron/spec/api-shell.spec.ts
@@ -38,7 +38,7 @@ describe('shell module', () => {
 
     afterEach(async () => {
       // reset env vars to prevent side effects
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         process.env.DE = envVars.de;
         process.env.BROWSER = envVars.browser;
         process.env.DISPLAY = envVars.display;
@@ -55,6 +55,11 @@ describe('shell module', () => {
       let requestReceived: Promise<any>;
       if (process.platform === 'linux') {
         process.env.BROWSER = '/bin/true';
+        process.env.DE = 'generic';
+        process.env.DISPLAY = '';
+        requestReceived = Promise.resolve();
+      } else if (process.platform === 'freebsd') {
+        process.env.BROWSER = '/usr/bin/true';
         process.env.DE = 'generic';
         process.env.DISPLAY = '';
         requestReceived = Promise.resolve();
