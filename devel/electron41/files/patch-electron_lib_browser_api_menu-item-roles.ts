--- electron/lib/browser/api/menu-item-roles.ts.orig	2026-06-29 04:13:32 UTC
+++ electron/lib/browser/api/menu-item-roles.ts
@@ -2,7 +2,7 @@ const isWindows = process.platform === 'win32';
 
 const isMac = process.platform === 'darwin';
 const isWindows = process.platform === 'win32';
-const isLinux = process.platform === 'linux';
+const isLinux = (process.platform === 'linux' || process.platform === 'freebsd');
 
 type RoleId =
   | 'about'
