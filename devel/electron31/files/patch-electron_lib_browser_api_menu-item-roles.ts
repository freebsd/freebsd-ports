--- electron/lib/browser/api/menu-item-roles.ts.orig	2022-05-18 15:31:32 UTC
+++ electron/lib/browser/api/menu-item-roles.ts
@@ -2,7 +2,7 @@ import { app, BrowserWindow, session, webContents, Web
 
 const isMac = process.platform === 'darwin';
 const isWindows = process.platform === 'win32';
-const isLinux = process.platform === 'linux';
+const isLinux = (process.platform === 'linux' || process.platform === 'freebsd');
 
 type RoleId = 'about' | 'close' | 'copy' | 'cut' | 'delete' | 'forcereload' | 'front' | 'help' | 'hide' | 'hideothers' | 'minimize' |
   'paste' | 'pasteandmatchstyle' | 'quit' | 'redo' | 'reload' | 'resetzoom' | 'selectall' | 'services' | 'recentdocuments' | 'clearrecentdocuments' |
