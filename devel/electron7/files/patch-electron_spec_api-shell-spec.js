--- electron/spec/api-shell-spec.js.orig	2019-12-13 19:48:14 UTC
+++ electron/spec/api-shell-spec.js
@@ -42,7 +42,7 @@ describe('shell module', () => {
       await closeWindow(w)
       w = null
       // reset env vars to prevent side effects
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         process.env.DE = envVars.de
         process.env.BROWSER = envVars.browser
         process.env.DISPLAY = envVars.display
@@ -54,6 +54,11 @@ describe('shell module', () => {
       let requestReceived
       if (process.platform === 'linux') {
         process.env.BROWSER = '/bin/true'
+        process.env.DE = 'generic'
+        process.env.DISPLAY = ''
+        requestReceived = Promise.resolve()
+      } else if (process.platform === 'freebsd') {
+        process.env.BROWSER = '/usr/bin/true'
         process.env.DE = 'generic'
         process.env.DISPLAY = ''
         requestReceived = Promise.resolve()
