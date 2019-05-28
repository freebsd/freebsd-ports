--- electron/lib/browser/api/menu-item-roles.js.orig	2019-05-23 00:29:28 UTC
+++ electron/lib/browser/api/menu-item-roles.js
@@ -5,7 +5,7 @@ const { app } = require('electron')
 const roles = {
   about: {
     get label () {
-      return process.platform === 'linux' ? 'About' : `About ${app.getName()}`
+      return (process.platform === 'linux' || process.platform === 'freebsd') ? 'About' : `About ${app.getName()}`
     }
   },
   close: {
