--- electron/lib/browser/api/dialog.ts.orig	2024-10-09 13:53:06 UTC
+++ electron/lib/browser/api/dialog.ts
@@ -41,7 +41,7 @@ const normalizeAccessKey = (text: string) => {
   // existing single underscores with a second underscore, replace double
   // ampersands with a single ampersand, and replace a single ampersand with
   // a single underscore
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     return text.replaceAll('_', '__').replaceAll(/&(.?)/g, (match, after) => {
       if (after === '&') return after;
       return `_${after}`;
