--- electron/spec/api-shell-spec.js.orig	2019-12-17 03:11:25 UTC
+++ electron/spec/api-shell-spec.js
@@ -35,7 +35,7 @@ describe('shell module', () => {
       await closeWindow(w)
       w = null
       // reset env vars to prevent side effects
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         process.env.DE = envVars.de
         process.env.BROWSER = envVars.browser
         process.env.DISPLAY = envVars.display
@@ -48,6 +48,10 @@ describe('shell module', () => {
         process.env.BROWSER = '/bin/true'
         process.env.DE = 'generic'
         process.env.DISPLAY = ''
+      } else if (process.platform === 'freebsd') {
+        process.env.BROWSER = '/usr/bin/true'
+        process.env.DE = 'generic'
+        process.env.DISPLAY = ''
       }
 
       // Ensure an external window is activated via a new window's blur event
@@ -64,7 +68,7 @@ describe('shell module', () => {
 
       shell.openExternal(url).then(() => {
         promiseResolved = true
-        if (blurEventEmitted || process.platform === 'linux') {
+        if (blurEventEmitted || process.platform === 'linux' || process.platform === 'freebsd') {
           done()
         }
       })
@@ -75,6 +79,10 @@ describe('shell module', () => {
       if (process.platform === 'linux') {
         process.env.DE = 'generic'
         process.env.DE = '/bin/true'
+        process.env.DISPLAY = ''
+      } else if (process.platform === 'freebsd') {
+        process.env.DE = 'generic'
+        process.env.DE = '/usr/bin/true'
         process.env.DISPLAY = ''
       }
 
