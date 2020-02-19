--- src/main-process/atom-application.js.orig	2019-10-21 17:33:40 UTC
+++ src/main-process/atom-application.js
@@ -463,7 +463,7 @@ module.exports = class AtomApplication extends EventEm
       if (this.applicationMenu != null) {
         this.applicationMenu.enableWindowSpecificItems(false);
       }
-      if (['win32', 'linux'].includes(process.platform)) {
+      if (['win32', 'linux', 'freebsd'].includes(process.platform)) {
         app.quit();
         return;
       }
