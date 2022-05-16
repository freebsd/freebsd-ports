--- electron/lib/browser/api/dialog.ts.orig	2021-11-15 23:45:07 UTC
+++ electron/lib/browser/api/dialog.ts
@@ -40,7 +40,7 @@ const normalizeAccessKey = (text: string) => {
   // existing single underscores with a second underscore, replace double
   // ampersands with a single ampersand, and replace a single ampersand with
   // a single underscore
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     return text.replace(/_/g, '__').replace(/&(.?)/g, (match, after) => {
       if (after === '&') return after;
       return `_${after}`;
