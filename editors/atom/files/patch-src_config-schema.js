--- src/config-schema.js.orig	2019-10-21 17:33:40 UTC
+++ src/config-schema.js
@@ -614,12 +614,12 @@ const configSchema = {
   }
 };
 
-if (['win32', 'linux'].includes(process.platform)) {
+if (['win32', 'linux', 'freebsd'].includes(process.platform)) {
   configSchema.core.properties.autoHideMenuBar = {
     type: 'boolean',
     default: false,
     description:
-      'Automatically hide the menu bar and toggle it by pressing Alt. This is only supported on Windows & Linux.'
+      'Automatically hide the menu bar and toggle it by pressing Alt. This is only supported on Windows, Linux & FreeBSD.'
   };
 }
 
