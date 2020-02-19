--- apm/node_modules/atom-package-manager/lib/auth.js.orig	2019-12-27 05:53:35 UTC
+++ apm/node_modules/atom-package-manager/lib/auth.js
@@ -6,7 +6,7 @@
   } catch (error1) {
     error = error1;
     // Gracefully handle keytar failing to load due to missing library on Linux
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       keytar = {
         findPassword: function() {
           return Promise.reject();
