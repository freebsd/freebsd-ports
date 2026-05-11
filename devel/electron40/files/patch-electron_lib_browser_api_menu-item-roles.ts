--- electron/lib/browser/api/menu-item-roles.ts.orig	2026-05-08 13:55:13 UTC
+++ electron/lib/browser/api/menu-item-roles.ts
@@ -10,7 +10,7 @@ const isWindows = process.platform === 'win32';
 
 const isMac = process.platform === 'darwin';
 const isWindows = process.platform === 'win32';
-const isLinux = process.platform === 'linux';
+const isLinux = (process.platform === 'linux' || process.platform === 'freebsd');
 
 type RoleId =
   | 'about'
