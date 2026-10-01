--- electron/lib/browser/api/menu-item-roles.ts.orig	2026-09-30 08:48:04 UTC
+++ electron/lib/browser/api/menu-item-roles.ts
@@ -3,7 +3,7 @@ const isWindows = process.platform === 'win32';
 
 const isMac = process.platform === 'darwin';
 const isWindows = process.platform === 'win32';
-const isLinux = process.platform === 'linux';
+const isLinux = (process.platform === 'linux' || process.platform === 'freebsd');
 
 type RoleId =
   | 'about'
