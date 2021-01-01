--- electron/lib/browser/api/dialog.js.orig	2019-05-23 04:03:08 UTC
+++ electron/lib/browser/api/dialog.js
@@ -54,7 +54,7 @@ const normalizeAccessKey = (text) => {
   // existing single underscores with a second underscore, replace double
   // ampersands with a single ampersand, and replace a single ampersand with
   // a single underscore
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     return text.replace(/_/g, '__').replace(/&(.?)/g, (match, after) => {
       if (after === '&') return after
       return `_${after}`
