--- electron/lib/browser/api/menu-item-roles.js.orig	2020-05-18 21:17:08 UTC
+++ electron/lib/browser/api/menu-item-roles.js
@@ -4,7 +4,7 @@ const { app } = require('electron');
 
 const isMac = process.platform === 'darwin';
 const isWindows = process.platform === 'win32';
-const isLinux = process.platform === 'linux';
+const isLinux = (process.platform === 'linux' || process.platform === 'freebsd');
 
 const roles = {
   about: {
