--- script/lib/dump-symbols.js.orig	2019-10-21 17:33:40 UTC
+++ script/lib/dump-symbols.js
@@ -6,9 +6,9 @@ const path = require('path');
 
 const CONFIG = require('../config');
 module.exports = function() {
-  if (process.platform === 'win32') {
+  if (process.platform === 'win32' || process.platform === 'freebsd') {
     console.log(
-      'Skipping symbol dumping because minidump is not supported on Windows'
+      'Skipping symbol dumping because minidump is not supported on Windows or FreeBSD'
         .gray
     );
     return Promise.resolve();
