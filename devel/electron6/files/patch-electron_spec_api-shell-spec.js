--- electron/spec/api-shell-spec.js.orig	2019-09-11 17:30:11 UTC
+++ electron/spec/api-shell-spec.js
@@ -37,7 +37,7 @@ describe('shell module', () => {
       await closeWindow(w)
       w = null
       // reset env vars to prevent side effects
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         process.env.DE = envVars.de
         process.env.BROWSER = envVars.browser
         process.env.DISPLAY = envVars.display
@@ -52,6 +52,11 @@ describe('shell module', () => {
         process.env.DE = 'generic'
         process.env.DISPLAY = ''
         requestReceived = Promise.resolve()
+      } else if (process.platform === 'freebsd') {
+        process.env.BROWSER = '/usr/bin/true'
+        process.env.DE = 'generic'
+        process.env.DISPLAY = ''
+        requestReceived = Promise.resolve()
       } else if (process.platform === 'darwin') {
         // On the Mac CI machines, Safari tries to ask for a password to the
         // code signing keychain we set up to test code signing (see
@@ -79,6 +84,10 @@ describe('shell module', () => {
       if (process.platform === 'linux') {
         process.env.DE = 'generic'
         process.env.DE = '/bin/true'
+        process.env.DISPLAY = ''
+      } else if (process.platform === 'freebsd') {
+        process.env.BROWSER = '/usr/bin/true'
+        process.env.DE = 'generic'
         process.env.DISPLAY = ''
       }
 
