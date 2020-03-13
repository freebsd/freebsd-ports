--- electron/lib/browser/api/dialog.js.orig	2019-12-13 19:48:14 UTC
+++ electron/lib/browser/api/dialog.js
@@ -28,7 +28,7 @@ const normalizeAccessKey = (text) => {
   // existing single underscores with a second underscore, replace double
   // ampersands with a single ampersand, and replace a single ampersand with
   // a single underscore
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     return text.replace(/_/g, '__').replace(/&(.?)/g, (match, after) => {
       if (after === '&') return after
       return `_${after}`
